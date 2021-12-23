/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:24:33 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/24 17:12:35 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	clear_object(t_obj_group **group)
{
	t_obj_group		*tmp;

	while (*group)
	{
		free((*group)->object);
		tmp = *group;
		(*group) = (*group)->next;
		free(tmp);
	}
}

int		init_obj_group(t_obj_group **group, char **strs,
					int (*init)(void **, char **),
					int (*hit)(void *, t_ray *, t_hit *))
{
	(*group) = (t_obj_group *)malloc(sizeof(t_obj_group));
	if (*group == NULL)
		return (0);
	if (!init(&(*group)->object, strs))
		return (0);
	(*group)->angle = new_vec(0.0, 0.0, 0.0);
	(*group)->hit = hit;
	(*group)->next = NULL;
	return (1);
}

int		add_obj_event(t_obj_group *group,
					void (*translate)(void *, int),
					void (*rotate)(void *, int, double),
					void (*scale)(void *, int))
{
	group->translate = translate;
	group->rotate = rotate;
	group->scale = scale;
	return (1);
}
