/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:39:07 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/29 18:52:30 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	clear_light(t_light **light)
{
	t_light		*tmp;

	while (*light)
	{
		tmp = *light;
		*light = (*light)->next;
		free(tmp);
	}
}

int		init_light(t_light **light, char **strs)
{
	*light = (t_light *)malloc(sizeof(t_light));
	if (*light == NULL)
		return (0);
	ft_atov(strs[1], &(*light)->point);
	(*light)->ratio = ft_atof(strs[2]);
	ft_atov(strs[3], &(*light)->color);
	(*light)->next = NULL;
	return (1);
}

int		create_l(t_world *world, char **strs)
{
	t_light		*new_light;
	t_light		*tmp;

	new_light = NULL;
	tmp = NULL;
	if (!world->light)
	{
		if (!init_light(&world->light, strs))
			return (0);
	}
	else
	{
		if (!init_light(&new_light, strs))
			return (0);
		tmp = world->light;
		world->light = new_light;
		new_light->next = tmp;
	}
	return (1);
}
