/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 02:50:28 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 08:50:27 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "world.h"

void		clear_world(t_world **world)
{
	clear_object(&(*world)->obj_group);
	clear_light(&(*world)->light);
	clear_cam(&(*world)->cam, (*world)->cam_num);
	clear_ambient(&(*world)->ambient);
	clear_resolution(&(*world)->resolution);
	free(*world);
}

int			init_world(t_world **world)
{
	*world = (t_world *)malloc(sizeof(t_world));
	if (!(*world))
		return (0);
	(*world)->obj_group = NULL;
	(*world)->light = NULL;
	(*world)->cam = NULL;
	(*world)->ambient = NULL;
	(*world)->resolution = NULL;
	(*world)->cam_num = 0;
	return (1);
}

t_world		*create_world(t_info *info)
{
	t_world		*world;

	printf("Creating world...\n");
	if (!(init_world(&world)))
		return (NULL);
	while (info)
	{
		if (!create_members(world, info->elem, info->elem[0]))
		{
			clear_world(&world);
			return (NULL);
		}
		info = info->next;
	}
	clear_info(&info);
	printf("Completed creating world!\n");
	return (world);
}
