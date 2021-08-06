/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:46:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/07 04:19:29 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "simulate.h"

void	*elapsed_timer(void *param)
{
	t_shared	*shared;
	t_simul		*simul;
	t_uint64	start;

	simul = (t_simul *)param;
	shared = &simul->shared;
	while (shared->clock_status != CLOCK_START)
		usleep(100);
	start = get_time();
	while (check_elapsed_timer(simul))
		shared->elapsed_time = (get_time() - start) / TIME_UNIT;
	return ((void *) NULL);
}

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
		usleep(100);
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
	while (simul->shared.clock_status == CLOCK_NOT_START)
		usleep(100);
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
				if (!check_philo_died(simul))
					print_mutex(simul, philo.index, DEAD);
				pthread_mutex_lock(&simul->mutex.philo_mutex);
				simul->shared.philo_status = DEAD;
				pthread_mutex_unlock(&simul->mutex.philo_mutex);
				return ((void *) NULL);
			}
		}
		usleep(100);
	}
	return ((void *) NULL);
}
