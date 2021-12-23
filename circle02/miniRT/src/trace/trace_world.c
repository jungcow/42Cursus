/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:11:45 by jungwkim          #+#    #+#             */
/*   Updated: 2021/10/23 11:35:42 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "../vec/vec.h"
#include "utils/utils.h"

int		trace_world(t_world *world, t_ray *ray, t_hit *hit)
{
	double		time;
	t_hit		tmp_hit;
	t_ray		tmp_ray;
	t_obj_group	*obj_group;

	time = -1.0f;
	obj_group = world->obj_group;
	while (obj_group)
	{
		if (obj_group->hit(obj_group->object, ray, hit))
		{
			if (time < 0 || (ray->time > 1.0e-6 && ray->time < time))
			{
				tmp_hit = *hit;
				tmp_ray = *ray;
				time = ray->time;
			}
		}
		obj_group = obj_group->next;
	}
	if (time == -1.0f)
		return (0);
	*ray = tmp_ray;
	*hit = tmp_hit;
	return (1);
}
