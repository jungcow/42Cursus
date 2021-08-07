/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:46:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/08 01:46:58 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

void	*elapsed_timer(void *param)
{
	t_shared	*shared;
	t_simul		*simul;
	t_uint64	start;

	simul = (t_simul *)param;
	shared = &simul->shared;
	while (shared->clock_status == CLOCK_NOT_START)
		;
	start = get_time();
	while (check_elapsed_timer(simul))
		shared->elapsed_time = (get_time() - start) / TIME_UNIT;
	return ((void *) NULL);
}

static int	death_timer(t_uint64 time, t_simul *simul, t_philo *philo)
{
	t_uint64	start;
	t_uint64	micro_time;

	start = get_time();
	micro_time = time * TIME_UNIT;
	while ((get_time() - start) / micro_time <= 0)
	{
		if (simul->shared.philo_status == DEAD)
			break ;
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
	while (simul->shared.clock_status == CLOCK_NOT_START
		|| simul->shared.timer_status[philo->index] != DEATH_TIMER_ON)
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
			if (!death_timer(simul->info.time_to_die, simul, &philo))
			{
				if (!check_philo_died(simul))
					print_mutex(simul, philo.index, DEAD);
				return ((void *) NULL);
			}
		}
	}
	return ((void *) NULL);
}
