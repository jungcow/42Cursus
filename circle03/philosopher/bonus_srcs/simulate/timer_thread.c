/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:46:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:34:27 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bonus/simulate.h"

static int	death_timer(t_uint64 time, t_simul *simul)
{
	while ((get_time() - simul->last_eat_time) / time <= 0)
	{
		if (simul->simul_status == DONE)
			return (1);
		usleep(200);
	}
	return (0);
}

void	*monitoring(void *param)
{
	t_simul	*simul;

	simul = (t_simul *)param;
	while (simul->philo_status == LIVE && simul->simul_status != DONE)
	{
		if (!death_timer(simul->info.time_to_die, simul))
		{
			print_record(simul, simul->index, DEAD);
			exit(1);
		}
	}
	return ((void *) NULL);
}
