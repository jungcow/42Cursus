/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:55:56 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:29 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "event.h"
#include "world/create/create.h"

void	switch_cam(t_trace *trace)
{
	trace->event->selected_cam = trace->event->selected_cam->next;
	if (trace->event->selected_cam == NULL)
		trace->event->selected_cam = trace->world->cam;
	trace->world->cam = trace->event->selected_cam;
	printf("Changing Camera!\n");
}

void	init_point(t_vec *point, int keycode)
{
	if (keycode == ARROW_LEFT)
		*point = new_vec(-1, 0, 0);
	else if (keycode == ARROW_RIGHT)
		*point = new_vec(1, 0, 0);
	else if (keycode == KEY_B)
		*point = new_vec(0, 0, -1);
	else if (keycode == KEY_F)
		*point = new_vec(0, 0, 1);
	else if (keycode == ARROW_DOWN)
		*point = new_vec(0, 1, 0);
	else if (keycode == ARROW_UP)
		*point = new_vec(0, -1, 0);
}

void	translate_cam(int keycode, t_trace *trace)
{
	t_cam	*cam;
	t_vec	point;

	cam = trace->event->selected_cam;
	init_point(&point, keycode);
	apply_metrix(cam->metrix, &point);
	cam->point = add_vec(cam->point, point);
}

void	rotate_cam(int keycode, t_trace *trace)
{
	t_cam	*cam;
	int		shift;

	cam = trace->event->selected_cam;
	shift = trace->event->shift;
	if (keycode == KEY_P)
	{
		if (shift == 0)
			cam->pan += 0.3;
		else
			cam->pan -= 0.3;
	}
	else if (keycode == KEY_T)
	{
		if (shift == 0)
			cam->tilt += 0.3;
		else
			cam->tilt -= 0.3;
	}
	init_cam_metrix(&cam->metrix, cam->pan, cam->tilt);
}

void	event_cam(int keycode, t_trace *trace)
{
	if ((keycode >= ARROW_LEFT && keycode <= ARROW_UP)
			|| keycode == KEY_F || keycode == KEY_B)
		translate_cam(keycode, trace);
	else if (keycode == KEY_P || keycode == KEY_T)
		rotate_cam(keycode, trace);
}
