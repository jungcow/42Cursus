/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:59:21 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/08 01:53:32 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "simulate.h"

#include <stdio.h>
static void	take_fork(t_simul *simul, t_philo *philo, int mode)
{
	if (mode == TAKE)
	{
		if (philo->index % 2)
			pthread_mutex_lock(&simul->mutex.forks[philo->lfork]);
		pthread_mutex_lock(&simul->mutex.forks[philo->rfork]);
		if (philo->index % 2 == 0)
			pthread_mutex_lock(&simul->mutex.forks[philo->lfork]);
	}
	else if (mode == PUT)
	{
		if (philo->index % 2)
			pthread_mutex_unlock(&simul->mutex.forks[philo->lfork]);
		pthread_mutex_unlock(&simul->mutex.forks[philo->rfork]);
		if (philo->index % 2 == 0)
			pthread_mutex_unlock(&simul->mutex.forks[philo->lfork]);
	}
}

static int	eating(t_simul *simul, t_philo *philo)
{
	if (philo->lfork == philo->rfork)
		return (0);
	take_fork(simul, philo, TAKE);
	print_mutex(simul, philo->index, FORK);
	/*
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	simul->shared.timer_status[philo->index] = DEATH_TIMER_OFF;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	while (check_timer_off_confirmed(simul, philo) == NOT_CONFIRMED)
		if (simul->shared.philo_status == DEAD)
			break ;
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	simul->shared.timer_status[philo->index] = DEATH_TIMER_ON;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	*/
	print_mutex(simul, philo->index, EATING);
	ft_sleep(simul->info.time_to_eat, simul);
	take_fork(simul, philo, PUT);
	return (0);
}

static int	sleeping(t_simul *simul, t_philo *philo)
{
	print_mutex(simul, philo->index, SLEEPING);
	ft_sleep(simul->info.time_to_sleep, simul);
	return (0);
}

static void	init_philo_thread(t_simul *simul, t_philo *philo)
{
	pthread_mutex_lock(&simul->mutex.philo_id_mutex);
	*philo = simul->philo[simul->index];
	philo->index = simul->index;
	simul->shared.timer_status[philo->index] = DEATH_TIMER_ON;
	simul->index++;
	pthread_mutex_unlock(&simul->mutex.philo_id_mutex);
	while (simul->shared.clock_status == CLOCK_NOT_START
		&& simul->shared.philo_status == LIVE)
		;
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
			{
				printf("[%d] 철학자 종료\n", philo.index + 1);
				return ((void *) NULL);
			}
		print_mutex(simul, philo.index, THINKING);
		if (num == 0 && (philo.index + 1) % 2 == 0)
			ft_sleep(simul->info.time_to_eat / 2, simul);
		if (simul->shared.philo_status == DEAD || eating(simul, &philo) == DEAD)
		{
			printf("[%d] 철학자 종료\n", philo.index + 1);
			return ((void *) NULL);
		}
	}
	printf("[%d] 철학자 종료\n", philo.index + 1);
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo.index]);
	simul->shared.timer_status[philo.index] = DEATH_TIMER_OFF;
	simul->shared.philo_status = DEAD;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo.index]);
	return ((void *) NULL);
}
