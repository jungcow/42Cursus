/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:46:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/08 23:39:51 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "simulate.h"

void	*elapsed_timer(void *param)
{
	t_shared	*shared;
	t_simul		*simul;
	t_uint64	num;

	simul = (t_simul *)param;
	shared = &simul->shared;
	while (shared->clock_status == CLOCK_NOT_START
		&& shared->philo_status == LIVE)
		;
	num = 0;
	while (shared->philo_status == LIVE && shared->clock_status == CLOCK_START)
	{
		usleep(500);
		if (++num == 2)
		{
			shared->elapsed_time += 1;
			num = 0;
		}
	}
	return ((void *) NULL);
}

int	check_death_timer(t_simul *simul, t_philo *philo,
					t_uint64 time)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.start_mutex[philo->index]);
	if ((simul->shared.elapsed_time - simul->shared.start_time[philo->index])
		/ (time) <= 0)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.start_mutex[philo->index]);
	return (flag);
}

static int	death_timer(t_uint64 time, t_simul *simul, t_philo *philo)
{
	while (check_death_timer(simul, philo, time))
	{
		if (simul->shared.simul_status[philo->index] == DONE)
			return (1);
		if (simul->shared.philo_status == DEAD)
			break ;
		usleep(500);
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
		;
}

void	*monitoring(void *param)
{
	t_simul	*simul;
	t_philo	philo;

	simul = (t_simul *)param;
	init_monitoring_thread(simul, &philo);
	while (simul->shared.philo_status == LIVE
		&& simul->shared.simul_status[philo.index] != DONE)
	{
		if (!death_timer(simul->info.time_to_die, simul, &philo))
		{
			if (!check_philo_died(simul))
				print_mutex(simul, philo.index, DEAD);
			return ((void *) NULL);
		}
	}
	return ((void *) NULL);
}
