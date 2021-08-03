/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:38:27 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 03:21:49 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

#include <stdio.h>
int	check_elapsed_timer(t_simul *simul)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.clock_mutex);
	pthread_mutex_lock(&simul->mutex.philo_mutex);
	if (simul->shared.philo_status == LIVE
		&& simul->shared.clock_status == CLOCK_START)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.philo_mutex);
	pthread_mutex_unlock(&simul->mutex.clock_mutex);
	return (flag);
}

int	check_timer_keepgoing(t_simul *simul, t_uint64 time, t_uint64 start)
{
	int			flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.philo_mutex);
	if ((get_time() - start) <= time
		&& simul->shared.philo_status == LIVE)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.philo_mutex);
	return (flag);
}

int	check_monitoring(t_simul *simul, t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	pthread_mutex_lock(&simul->mutex.philo_mutex);
	if (simul->shared.timer_status[philo->index] != DEATH_TIMER_DONE
		&& simul->shared.philo_status == LIVE)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.philo_mutex);
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	return (flag);
}
