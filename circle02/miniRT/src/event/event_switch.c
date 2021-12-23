/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_switch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 00:35:40 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 09:05:50 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "event.h"

void	switch_selection(int key, t_trace *trace)
{
	if (key == KEY_C)
	{
		trace->event->selected = 'C';
		printf("SELECT : CAMERA\n");
		switch_cam(trace);
	}
	else if (key == KEY_O)
	{
		trace->event->selected = 'O';
		printf("SELECT : OBJECT\n");
		switch_obj(trace);
	}
}

void	switch_shift_key(t_trace *trace)
{
	if (trace->event->shift == 1)
	{
		printf("SHIFT OFF\n");
		trace->event->shift = 0;
	}
	else if (trace->event->shift == 0)
	{
		printf("SHIFT ON\n");
		trace->event->shift = 1;
	}
}
