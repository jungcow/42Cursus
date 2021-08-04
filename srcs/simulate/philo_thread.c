/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:59:21 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 23:47:49 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "simulate.h"

static int	thinking(t_simul *simul, t_philo *philo)
{
	int	i;
	int	philo_idx;
	int	max_simultaneous;
	int	simul_index;

	philo_idx = philo->index + 1;
	if (philo_idx == simul->info.philo_num)
		philo_idx = 0;
	max_simultaneous = simul->info.philo_num / 2;
	simul_index = (simul->shared.simul_num / max_simultaneous) + 1;
	i = -1;
	while (++i < max_simultaneous)
		if (philo_idx == ((simul_index % simul->info.philo_num) + (i * 2))
			% simul->info.philo_num)
			return (0);
	return (1);
}

static int	eating(t_simul *simul, t_philo *philo)
{
	pthread_mutex_lock(&simul->mutex.forks[philo->rfork]);
	pthread_mutex_lock(&simul->mutex.forks[philo->lfork]);
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	simul->shared.timer_status[philo->index] = DEATH_TIMER_OFF;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	print_mutex(simul, philo->index, EATING);
	while (simul->shared.philo_status == LIVE
		&& check_timer_off_confirmed(simul, philo) == NOT_CONFIRMED)
		;
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	simul->shared.timer_status[philo->index] = DEATH_TIMER_ON;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	ft_sleep(simul->info.time_to_eat * TIME_UNIT, simul);
	pthread_mutex_unlock(&simul->mutex.forks[philo->lfork]);
	pthread_mutex_unlock(&simul->mutex.forks[philo->rfork]);
	pthread_mutex_lock(&simul->mutex.simul_num_mutex);
	simul->shared.simul_num++;
	pthread_mutex_unlock(&simul->mutex.simul_num_mutex);
	return (simul->shared.philo_status);
}

static int	sleeping(t_simul *simul, t_philo *philo)
{
	print_mutex(simul, philo->index, SLEEPING);
	ft_sleep(simul->info.time_to_sleep * TIME_UNIT, simul);
	return (simul->shared.philo_status);
}

static void	init_philo_thread(t_simul *simul, t_philo *philo)
{
	pthread_mutex_lock(&simul->mutex.philo_id_mutex);
	*philo = simul->philo[simul->index];
	philo->index = simul->index;
	simul->index++;
	pthread_mutex_unlock(&simul->mutex.philo_id_mutex);
	while (simul->shared.clock_status == CLOCK_NOT_START
		&& simul->shared.philo_status == LIVE)
		;
	simul->shared.start[philo->index] = get_time();
	simul->shared.timer_status[philo->index] = DEATH_TIMER_ON;
}

void	*philosopher(void *param)
{
	t_simul			*simul;
	t_philo			philo;
	unsigned int	num;

	simul = (t_simul *)param;
	init_philo_thread(simul, &philo);
	num = -1;
	while (simul->shared.philo_status == LIVE
		&& ++num < simul->info.max_eat_num)
	{
		if (num != 0)
			if (simul->shared.philo_status == DEAD
				|| sleeping(simul, &philo) == DEAD)
				return ((void *) NULL);
		print_mutex(simul, philo.index, THINKING);
		while (simul->shared.philo_status == LIVE && thinking(simul, &philo))
			;
		if (simul->shared.philo_status == DEAD || eating(simul, &philo) == DEAD)
			return ((void *) NULL);
	}
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo.index]);
	simul->shared.timer_status[philo.index] = DEATH_TIMER_DONE;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo.index]);
	return ((void *) NULL);
}
