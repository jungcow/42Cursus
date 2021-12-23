/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 08:18:43 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 08:44:41 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "world/world.h"
#include "trace/trace.h"

int		event_button(t_trace *trace)
{
	terminate_program(trace);
	return (1);
}
