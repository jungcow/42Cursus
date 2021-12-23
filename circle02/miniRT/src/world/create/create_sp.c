/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:28:47 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/12 18:05:59 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include <math.h>

int		hit_sphere(void *obj, t_ray *ray, t_hit *hit)
{
	t_sphere	*sphere;
	double		a;
	double		b;
	double		c;
	t_vec		co;

	sphere = (t_sphere *)obj;
	co = sub_vec(ray->origin, sphere->center);
	a = dot_vec(ray->dir, ray->dir);
	b = 2 * dot_vec(co, ray->dir);
	c = dot_vec(co, co) - pow(sphere->diameter / 2, 2.0);
	if (!solve_quadratic(a, b, c, ray))
		return (0);
	hit->color = sphere->color;
	hit->point = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	hit->normal = normalize_vec(sub_vec(hit->point, sphere->center));
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = multi_vec(hit->normal, -1);
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}

int		init_sphere(void **object, char **strs)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	ft_atov(strs[1], &sphere->center);
	sphere->diameter = ft_atof(strs[2]);
	ft_atov(strs[3], &sphere->color);
	*object = sphere;
	return (1);
}

int		create_sp(t_world *world, char **strs)
{
	t_obj_group		*new_group;
	t_obj_group		*tmp;

	if (!world->obj_group)
	{
		if (!init_obj_group(&world->obj_group, strs, init_sphere, hit_sphere))
			return (0);
		if (!add_obj_event(world->obj_group,
					translate_sphere, rotate_sphere, scale_sphere))
			return (0);
	}
	else
	{
		if (!init_obj_group(&new_group, strs, init_sphere, hit_sphere))
			return (0);
		if (!add_obj_event(new_group,
					translate_sphere, rotate_sphere, scale_sphere))
			return (0);
		tmp = world->obj_group;
		world->obj_group = new_group;
		new_group->next = tmp;
	}
	return (1);
}
