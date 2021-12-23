/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:50:21 by jungwkim          #+#    #+#             */
/*   Updated: 2021/12/23 18:28:25 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "event.h"
#include "world/world.h"
#include "trace/trace.h"

void	terminate_program(t_trace *trace)
{
	printf("Program Terminated.\n");
	clear_world(&trace->world);
	clear_event(&trace->event);
	exit(0);
}

void	add_key(int key, t_trace *trace)
{
	printf("key: %X, %d\n", key, key);
	if (key == ESC)
		terminate_program(trace);
	else if (key == KEY_C || key == KEY_O)
		switch_selection(key, trace);
	else if (key == SHIFT)
		switch_shift_key(trace);
	else if (trace->event->selected == 'C'
			&& ((key >= ARROW_LEFT && key <= ARROW_UP)
			|| key == KEY_F || key == KEY_B || key == KEY_P || key == KEY_T))
		event_cam(key, trace);
	else if (trace->event->selected == 'O'
			&& ((key >= ARROW_LEFT && key <= ARROW_UP) || key == KEY_F
			|| key == KEY_B || key == KEY_X || key == KEY_Y || key == KEY_Z))
		event_obj(key, trace);
	printf("Selected [Object / Camera]: %c\n", trace->event->selected);
}

int		event_key(int keycode, void *param)
{
	t_trace		*t;

	t = (t_trace *)param;
	add_key(keycode, t);
	printf("removing previos image...\n");
	mlx_clear_window(t->mlx->ptr, t->mlx->win);
	printf("rendering new image...\n");
	trace(t->world, t->mlx);
	printf("Complete Rendering!\n");
	return (1);
}
