/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:38:27 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/07 04:16:26 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

int	check_elapsed_timer(t_simul *simul)
{
	int	flag;

	flag = 0;
	if (simul->shared.philo_status == LIVE
		&& simul->shared.clock_status == CLOCK_START)
		flag = 1;
	return (flag);
}

int	check_timer_keepgoing(t_simul *simul, t_uint64 time, t_uint64 start)
{
	int			flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.philo_mutex);
	if ((get_time() - start) / time == 0
		&& simul->shared.philo_status == LIVE)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.philo_mutex);
	return (flag);
}

int	check_monitoring(t_simul *simul, t_philo *philo)
{
	int			flag;
	int			flag2;

	flag = 0;
	flag2 = 0;
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	if (simul->shared.timer_status[philo->index] != DEATH_TIMER_DONE)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	pthread_mutex_lock(&simul->mutex.philo_mutex);
	if (simul->shared.philo_status == LIVE)
		flag2 = 1;
	pthread_mutex_unlock(&simul->mutex.philo_mutex);
	return (flag * flag2);
}
