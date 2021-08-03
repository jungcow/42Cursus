/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:53:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/02 21:42:02 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "simulate.h"

void	clear_philosopher(t_philo *philo)
{
	free(philo);
}

void	clear_mutex(t_mutex mutex)
{
	free(mutex.forks);
}

void	clear_shared(t_shared shared, int philo_num)
{
//	int	i;
	(void)philo_num;

//	i = 0;
//	while (i < philo_num)
//		free(shared.timer_status[i]);
	free(shared.timer_status);
}

void	clear_simulation(t_simul *simul)
{
	clear_philosopher(simul->philo);
	clear_mutex(simul->mutex);
	clear_shared(simul->shared, simul->info.philo_num);
	free(simul);
}
