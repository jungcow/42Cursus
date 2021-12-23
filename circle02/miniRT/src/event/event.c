/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:19:01 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 19:55:30 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "event.h"

void	clear_event(t_event **event)
{
	(*event)->selected_obj = NULL;
	(*event)->selected_cam = NULL;
	free(*event);
}

void	init_trace(t_trace *trace, t_world *world, t_mlx *mlx)
{
	trace->world = world;
	trace->mlx = mlx;
	trace->event = NULL;
}

void	init_event(t_trace *trace, t_event **event)
{
	*event = (t_event *)malloc(sizeof(t_event));
	(*event)->selected_obj = trace->world->obj_group;
	(*event)->selected_cam = trace->world->cam;
	(*event)->selected = 0;
	(*event)->shift = 0;
}

void	event_listener(t_world **world, t_mlx *mlx)
{
	t_trace		trace;

	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	system("leaks miniRT");
	init_trace(&trace, *world, mlx);
	init_event(&trace, &trace.event);
	printf("Start control!\n");
	mlx_hook(mlx->win, KEYPRESS, 1L << 0, event_key, &trace);
	mlx_hook(mlx->win, DESTROYNOTIFY, 1L << 17,
						event_button, &trace);
	mlx_loop(mlx->ptr);
}
