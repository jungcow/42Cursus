/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:36:02 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 08:49:30 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "trace.h"
#include "mlx.h"

void	init_ray(t_ray *ray, int x, int y, t_world *world)
{
	double		scale;
	t_cam		*cam;
	int			width;
	int			height;
	double		a_ratio;

	width = world->resolution->width;
	height = world->resolution->height;
	a_ratio = world->resolution->a_ratio;
	cam = world->cam;
	ray->origin = cam->point;
	scale = FOCAL_LEN * tan(deg_to_rad(cam->fov / 2));
	ray->dir.x = (2.0 * ((x + 0.5) / (double)width) - 1.0) * a_ratio * scale;
	ray->dir.y = (2.0 * ((y + 0.5) / (double)height) - 1.0) * scale;
	ray->dir.z = FOCAL_LEN;
	ray->dir = normalize_vec(ray->dir);
	apply_metrix(cam->metrix, &ray->dir);
	ray->time = 0.0f;
}

void	my_pixel_put(t_mlx *mlx, int x, int y, t_vec *rgb)
{
	char			*dst;
	unsigned int	color;

	dst = mlx->addr + (y * mlx->line + x * (mlx->bpp / 8));
	if (rgb == NULL)
		color = 0x000000;
	else
		color = ((unsigned int)rgb->x) * pow(2, 16.0)
			+ ((unsigned int)rgb->y) * pow(2, 8.0)
			+ ((unsigned int)rgb->z);
	*(unsigned int *)dst = color;
}

void	trace(t_world *world, t_mlx *mlx)
{
	int		x;
	int		y;
	t_ray	ray;
	t_hit	hit;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			init_ray(&ray, x, y, world);
			if (trace_world(world, &ray, &hit))
			{
				trace_light(world, &hit);
				my_pixel_put(mlx, x, y, &hit.color);
			}
			else
				my_pixel_put(mlx, x, y, NULL);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	printf("Rendering completed!\n");
}
