/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:33:45 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/10 00:52:50 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include <math.h>

void	clear_cam(t_cam **cam, int cam_num)
{
	t_cam	*tmp;
	int		i;

	i = -1;
	while (++i < cam_num)
	{
		tmp = *cam;
		*cam = (*cam)->next;
		free(tmp);
	}
}

void	init_cam_angle(double *p, double *t, t_vec dir)
{
	double	a;
	double	b;
	double	c;

	a = dir.x;
	b = dir.y;
	c = dir.z;
	*t = asin(c);
	if (c <= 1 + 1.0e-6 && c >= 1 - 1.0e-6)
		*p = 0;
	else
		*p = acos(b / cos(*t));
	if (a > 0)
		*p *= -1;
}

void	init_cam_metrix(t_vec (*metrix)[3], double p, double t)
{
	(*metrix)[0] = new_vec(
			cos(p),
			-1 * sin(p) * sin(t),
			-1 * sin(p) * cos(t));
	(*metrix)[1] = new_vec(
			sin(p),
			cos(p) * sin(t),
			cos(p) * cos(t));
	(*metrix)[2] = new_vec(
			0,
			-1 * cos(t),
			sin(t));
}

int		init_cam(t_cam **cam, char **strs, int *cam_num)
{
	*cam = (t_cam *)malloc(sizeof(t_cam));
	if (!(*cam))
		return (0);
	ft_atov(strs[1], &(*cam)->point);
	ft_atov(strs[2], &(*cam)->orient);
	(*cam)->orient = normalize_vec((*cam)->orient);
	init_cam_angle(&(*cam)->pan, &(*cam)->tilt, (*cam)->orient);
	init_cam_metrix(&(*cam)->metrix, (*cam)->pan, (*cam)->tilt);
	(*cam)->fov = ft_atof(strs[3]);
	(*cam)->focal_len = FOCAL_LEN;
	(*cam)->next = NULL;
	*cam_num += 1;
	return (1);
}

int		create_c(t_world *world, char **strs)
{
	t_cam	*new_cam;
	t_cam	*tmp;

	new_cam = NULL;
	tmp = NULL;
	if (!world->cam)
	{
		if (!init_cam(&world->cam, strs, &world->cam_num))
			return (0);
	}
	else
	{
		if (!init_cam(&new_cam, strs, &world->cam_num))
			return (0);
		if (!world->cam->next)
			new_cam->next = world->cam;
		else
		{
			tmp = world->cam->next;
			new_cam->next = tmp;
		}
		world->cam->next = new_cam;
	}
	return (1);
}
