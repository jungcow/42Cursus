/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_timer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 01:49:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/08 01:06:50 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

#include <stdio.h>
#include <unistd.h>
int	check_timer_off_confirmed(t_simul *simul, t_philo *philo)
{
	int	flag;

	flag = NOT_CONFIRMED;
	if (simul->shared.confirmed[philo->index] == CONFIRMED)
	{
		flag = CONFIRMED;
		pthread_mutex_lock(&simul->mutex.confirm_mutex[philo->index]);
		simul->shared.confirmed[philo->index] = NOT_CONFIRMED;
		pthread_mutex_unlock(&simul->mutex.confirm_mutex[philo->index]);
	}
	return (flag);
}

int	check_death_timer_off(t_simul *simul, t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	if (simul->shared.timer_status[philo->index] == DEATH_TIMER_OFF
		|| simul->shared.timer_status[philo->index] == DEATH_TIMER_DONE)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	return (flag);
}

int	check_death_timer_on(t_simul *simul, t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.timer_mutex[philo->index]);
	if (simul->shared.timer_status[philo->index] == DEATH_TIMER_ON)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.timer_mutex[philo->index]);
	return (flag);
}
