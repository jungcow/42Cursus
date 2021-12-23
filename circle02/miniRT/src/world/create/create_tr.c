/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:51:41 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/11 15:36:46 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int		hit_triangle(void *obj, t_ray *ray, t_hit *hit)
{
	t_triangle		*triangle;
	t_vec			vec1;
	t_vec			vec2;

	triangle = (t_triangle *)obj;
	vec1 = sub_vec(triangle->point2, triangle->point1);
	vec2 = sub_vec(triangle->point3, triangle->point2);
	if (!solve_plane(ray, triangle->point1, cross_vec(vec1, vec2)))
		return (0);
	if (!solve_triangle(ray,
				triangle->point1, triangle->point2, triangle->point3))
	{
		ray->time = 0.0f;
		return (0);
	}
	hit->color = triangle->color;
	hit->normal = normalize_vec(cross_vec(vec1, vec2));
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = multi_vec(hit->normal, -1);
	hit->point = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}

int		init_triangle(void **object, char **strs)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	if (!triangle)
		return (0);
	ft_atov(strs[1], &triangle->point1);
	ft_atov(strs[2], &triangle->point2);
	ft_atov(strs[3], &triangle->point3);
	ft_atov(strs[4], &triangle->color);
	*object = triangle;
	return (1);
}

int		create_tr(t_world *world, char **strs)
{
	t_obj_group		*new_group;
	t_obj_group		*tmp;

	if (!world->obj_group)
	{
		if (!init_obj_group(&world->obj_group, strs,
					init_triangle, hit_triangle))
			return (0);
		if (!add_obj_event(world->obj_group,
					translate_triangle, rotate_triangle, scale_triangle))
			return (0);
	}
	else
	{
		if (!init_obj_group(&new_group, strs, init_triangle, hit_triangle))
			return (0);
		if (!add_obj_event(new_group,
					translate_triangle, rotate_triangle, scale_triangle))
			return (0);
		tmp = world->obj_group;
		world->obj_group = new_group;
		new_group->next = tmp;
	}
	return (1);
}
