/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:53:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/07 03:48:19 by jungwkim         ###   ########.fr       */
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
	free(mutex.timer_mutex);
	free(mutex.confirm_mutex);
}

void	clear_shared(t_shared shared)
{
	free(shared.timer_status);
	free(shared.confirmed);
}

void	clear_simulation(t_simul *simul)
{
	clear_philosopher(simul->philo);
	clear_mutex(simul->mutex);
	clear_shared(simul->shared);
	free(simul->philo_ids);
	free(simul->monitor_ids);
	free(simul);
}
