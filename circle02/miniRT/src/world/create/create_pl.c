/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:23:52 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/12 18:05:29 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int		hit_plane(void *obj, t_ray *ray, t_hit *hit)
{
	t_plane		*plane;

	plane = (t_plane *)obj;
	if (!solve_plane(ray, plane->point, plane->orient))
		return (0);
	hit->color = plane->color;
	hit->normal = normalize_vec(plane->orient);
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = multi_vec(hit->normal, -1);
	hit->origin = ray->origin;
	hit->point = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	hit->dir = ray->dir;
	return (1);
}

int		init_plane(void **object, char **strs)
{
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (0);
	ft_atov(strs[1], &plane->point);
	ft_atov(strs[2], &plane->orient);
	plane->orient = normalize_vec(plane->orient);
	ft_atov(strs[3], &plane->color);
	*object = plane;
	return (1);
}

int		create_pl(t_world *world, char **strs)
{
	t_obj_group		*new_group;
	t_obj_group		*tmp;

	if (!world->obj_group)
	{
		if (!init_obj_group(&world->obj_group, strs, init_plane, hit_plane))
			return (0);
		if (!add_obj_event(world->obj_group,
					translate_plane, rotate_plane, scale_plane))
			return (0);
	}
	else
	{
		if (!init_obj_group(&new_group, strs, init_plane, hit_plane))
			return (0);
		if (!add_obj_event(new_group,
					translate_plane, rotate_plane, scale_plane))
			return (0);
		tmp = world->obj_group;
		world->obj_group = new_group;
		new_group->next = tmp;
	}
	return (1);
}
