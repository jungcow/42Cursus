/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:46:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 23:48:09 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

static int	death_timer(t_uint64 time, t_simul *simul, t_philo *philo)
{
	t_uint64	start;

	start = get_time();
	while (check_timer_keepgoing(simul, time, start))
	{
		if (check_death_timer_off(simul, philo))
		{
			pthread_mutex_lock(&simul->mutex.confirm_mutex[philo->index]);
			simul->shared.confirmed[philo->index] = CONFIRMED;
			pthread_mutex_unlock(&simul->mutex.confirm_mutex[philo->index]);
			return (1);
		}
	}
	return (0);
}

static void	init_monitoring_thread(t_simul *simul, t_philo *philo)
{
	pthread_mutex_lock(&simul->mutex.monitor_id_mutex);
	*philo = simul->philo[simul->monitor_index];
	philo->index = simul->monitor_index;
	simul->monitor_index++;
	pthread_mutex_unlock(&simul->mutex.monitor_id_mutex);
	while (simul->shared.clock_status == 0)
		;
}

void	*monitoring(void *param)
{
	t_simul	*simul;
	t_philo	philo;

	simul = (t_simul *)param;
	init_monitoring_thread(simul, &philo);
	while (check_monitoring(simul, &philo))
	{
		if (check_death_timer_on(simul, &philo))
		{
			if (!death_timer(simul->info.time_to_die
					* TIME_UNIT, simul, &philo))
			{
				if (simul->shared.philo_status != DEAD)
					print_mutex(simul, philo.index, DEAD);
				pthread_mutex_lock(&simul->mutex.philo_mutex);
				simul->shared.philo_status = DEAD;
				pthread_mutex_unlock(&simul->mutex.philo_mutex);
				return ((void *) NULL);
			}
		}
	}
	return ((void *) NULL);
}
