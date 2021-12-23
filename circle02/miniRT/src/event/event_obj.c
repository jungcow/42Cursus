/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 00:53:47 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 09:07:39 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "event.h"

void	switch_obj(t_trace *trace)
{
	trace->event->selected_obj = trace->event->selected_obj->next;
	if (trace->event->selected_obj == NULL)
		trace->event->selected_obj = trace->world->obj_group;
}

void	translate_obj(int key, t_trace *trace)
{
	t_obj_group		*obj_group;

	obj_group = trace->event->selected_obj;
	obj_group->translate(obj_group->object, key);
}

void	rotate_obj(int key, t_trace *trace)
{
	t_obj_group		*obj_group;

	obj_group = trace->event->selected_obj;
	obj_group->rotate(obj_group->object, key, 0.1);
}

void	scale_obj(int key, t_trace *trace)
{
	t_obj_group		*obj_group;

	obj_group = trace->event->selected_obj;
	obj_group->scale(obj_group->object, key);
}

void	event_obj(int key, t_trace *trace)
{
	if ((key >= ARROW_LEFT && key <= ARROW_UP) || key == KEY_F || key == KEY_B)
		translate_obj(key, trace);
	else if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		rotate_obj(key, trace);
	else if (key == KEY_E || key == KEY_R)
		scale_obj(key, trace);
}
