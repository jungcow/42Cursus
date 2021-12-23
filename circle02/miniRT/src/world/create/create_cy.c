/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:47:20 by jungwkim          #+#    #+#             */
/*   Updated: 2021/10/23 11:35:31 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include "utils/utils.h"

t_vec	get_normal(t_ray *ray, t_cylinder *cylinder, int flag)
{
	t_vec	hit;
	t_vec	cp;
	t_vec	u;
	t_vec	normal;

	(void)flag;
	hit = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	cp = sub_vec(hit, cylinder->point);
	u = multi_vec(cylinder->orient, dot_vec(cylinder->orient, cp));
	if (flag == 1)
		normal = normalize_vec(sub_vec(cp, u));
	else
		normal = normalize_vec(multi_vec(sub_vec(cp, u), -1));
	return (normal);
}

int		hit_cylinder(void *obj, t_ray *ray, t_hit *hit)
{
	t_cylinder		*cylinder;
	int				flag;

	cylinder = (t_cylinder *)obj;
	flag = solve_cylinder(ray, cylinder,
						cylinder->diameter / 2, cylinder->height);
	if (flag == 0)
	{
		ray->time = 0.0f;
		return (0);
	}
	hit->normal = normalize_vec(get_normal(ray, cylinder, flag));
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = multi_vec(hit->normal, -1);
	hit->color = cylinder->color;
	hit->point = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}

int		init_cylinder(void **object, char **strs)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (0);
	ft_atov(strs[1], &cylinder->point);
	ft_atov(strs[2], &cylinder->orient);
	cylinder->orient = normalize_vec(cylinder->orient);
	cylinder->diameter = ft_atof(strs[3]);
	cylinder->height = ft_atof(strs[4]);
	ft_atov(strs[5], &cylinder->color);
	*object = cylinder;
	return (1);
}

int		create_cy(t_world *world, char **strs)
{
	t_obj_group		*new_group;
	t_obj_group		*tmp;

	if (!world->obj_group)
	{
		if (!init_obj_group(&world->obj_group, strs,
					init_cylinder, hit_cylinder))
			return (0);
		if (!add_obj_event(world->obj_group,
					translate_cylinder, rotate_cylinder, scale_cylinder))
			return (0);
	}
	else
	{
		if (!init_obj_group(&new_group, strs, init_cylinder, hit_cylinder))
			return (0);
		if (!add_obj_event(new_group,
					translate_cylinder, rotate_cylinder, scale_cylinder))
			return (0);
		tmp = world->obj_group;
		world->obj_group = new_group;
		new_group->next = tmp;
	}
	return (1);
}
