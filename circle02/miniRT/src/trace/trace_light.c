/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:02:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/10/23 12:15:33 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include <math.h>

static void	init_shadow_ray(t_light *light, t_ray *shadow, t_hit *hit)
{
	shadow->origin = add_vec(hit->point, multi_vec(hit->normal, 1.0e-6));
	shadow->dir = normalize_vec(sub_vec(light->point, hit->point));
	shadow->time = 0.0f;
}

static void	phong_shading(t_light *light, t_ray *shadow,
											t_hit *hit, t_vec *ratio)
{
	t_vec	diffuse;
	t_vec	specular;

	diffuse = diffuse_light(light, shadow, hit);
	*ratio = add_vec(*ratio, diffuse);
	specular = specular_light(light, hit);
	*ratio = add_vec(*ratio, specular);
}

static int	block_light(t_world *world, t_ray *shadow,
										t_hit *dump, t_light *light)
{
	t_vec		tmp;
	double		dist;
	t_obj_group	*obj_group;

	obj_group = world->obj_group;
	tmp = sub_vec(light->point, shadow->origin);
	dist = sqrt(dot_vec(tmp, tmp));
	while (obj_group)
	{
		if (obj_group->hit(obj_group->object, shadow, dump))
			if (shadow->time > 1.0e-5 && shadow->time < dist)
				if (shadow->time < dist)
					return (1);
		obj_group = obj_group->next;
	}
	return (0);
}

void		trace_light(t_world *world, t_hit *hit)
{
	t_light		*light;
	t_ray		shadow;
	t_hit		tmp;
	t_vec		ratio;

	light = world->light;
	ratio = multi_vec(world->ambient->color, world->ambient->ratio / 255);
	while (light)
	{
		init_shadow_ray(light, &shadow, hit);
		if (dot_vec(shadow.dir, hit->normal) > 0
				&& !block_light(world, &shadow, &tmp, light))
			phong_shading(light, &shadow, hit, &ratio);
		light = light->next;
	}
	hit->color = vec_multi_vec(hit->color, ratio);
	hit->color.x = ft_min(hit->color.x, 255.0f);
	hit->color.y = ft_min(hit->color.y, 255.0f);
	hit->color.z = ft_min(hit->color.z, 255.0f);
}
