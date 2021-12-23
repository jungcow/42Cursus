/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:17:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/07 11:16:47 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "ft_stddef.h"
# include "key_def.h"
# include "event_def.h"
# include "mlx.h"

void		event_listener(t_world **world, t_mlx *mlx);
int			event_key(int keycode, void *trace);
int			event_button(t_trace *trace);

void		clear_event(t_event **event);
void		terminate_program(t_trace *trace);

/*
**	event_switch.c
*/
void		switch_selection(int key, t_trace *trace);
void		switch_shift_key(t_trace *trace);

/*
**	event_cam.c
*/
void		event_cam(int keycode, t_trace *trace);
void		switch_cam(t_trace *trace);

/*
**	event_obj.c
*/
void		event_obj(int keycode, t_trace *trace);
void		switch_obj(t_trace *trace);

#endif
