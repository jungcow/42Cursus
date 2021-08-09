/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:46:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 23:09:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bonus/simulate.h"

static int	death_timer(t_uint64 time, t_simul *simul)
{
	t_uint64	num;

	num = 0;
//	while (check_death_timer(simul, philo, time))
	while ((simul->elapsed_time - simul->start_time) / time <= 0)
	{
		if (simul->simul_status == DONE)
			return (1);
		usleep(500);
		if (++num % 2 == 0)
			simul->elapsed_time += 1;
	}
	return (0);
}

void	*monitoring(void *param)
{
	t_simul *simul;

	simul = (t_simul *)param;
	while (simul->philo_status == LIVE)
	{
		if (!death_timer(simul->info.time_to_die, simul))
		{
			print_record(simul, simul->index, DEAD);
			exit(DEAD);
//			return ((void *) NULL);
		}
	}
	return ((void *) NULL);
}
