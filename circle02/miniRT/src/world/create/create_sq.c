/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:38:13 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/12 18:05:08 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include <math.h>

void	init_vertex(t_vec *metrix, t_vec *vertex, t_vec center, double size)
{
	int		i;
	double	d;

	d = size / sqrt(2.0f);
	vertex[0] = new_vec(d, 0, 0);
	vertex[1] = new_vec(0, d, 0);
	vertex[2] = new_vec(-1 * d, 0, 0);
	vertex[3] = new_vec(0, -1 * d, 0);
	i = 0;
	while (i < 4)
	{
		apply_metrix(metrix, &vertex[i]);
		translate(center, &vertex[i]);
		i++;
	}
}

int		hit_square(void *obj, t_ray *ray, t_hit *hit)
{
	t_square	*square;
	t_vec		metrix[3];

	square = (t_square *)obj;
	random_axis_rotate(metrix, square->orient);
	init_vertex(metrix, square->vertex, square->point, square->size);
	if (!solve_plane(ray, square->vertex[0], square->orient))
		return (0);
	if (!solve_triangle(ray,
				square->vertex[0], square->vertex[1], square->vertex[2])
			&& !solve_triangle(ray,
				square->vertex[0], square->vertex[2], square->vertex[3]))
	{
		ray->time = 0.0f;
		return (0);
	}
	hit->color = square->color;
	hit->normal = normalize_vec(square->orient);
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = multi_vec(hit->normal, -1);
	hit->point = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}

int		init_square(void **object, char **strs)
{
	t_square	*square;

	square = (t_square *)malloc(sizeof(t_square));
	if (!square)
		return (0);
	ft_atov(strs[1], &square->point);
	ft_atov(strs[2], &square->orient);
	square->size = ft_atof(strs[3]);
	ft_atov(strs[4], &square->color);
	*object = square;
	return (1);
}

int		create_sq(t_world *world, char **strs)
{
	t_obj_group		*new_group;
	t_obj_group		*tmp;

	if (!world->obj_group)
	{
		if (!init_obj_group(&world->obj_group, strs, init_square, hit_square))
			return (0);
		if (!add_obj_event(world->obj_group,
					translate_square, rotate_square, scale_square))
			return (0);
	}
	else
	{
		if (!init_obj_group(&new_group, strs, init_square, hit_square))
			return (0);
		if (!add_obj_event(new_group,
					translate_square, rotate_square, scale_square))
			return (0);
		tmp = world->obj_group;
		world->obj_group = new_group;
		new_group->next = tmp;
	}
	return (1);
}
