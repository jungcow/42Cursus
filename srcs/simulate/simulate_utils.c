/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:32:19 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 21:29:54 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"
#include "color.h"
#include "simulate.h"

int	check_philo_died(t_simul *simul)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&simul->mutex.philo_mutex);
	if (simul->shared.philo_status == DEAD)
		flag = 1;
	pthread_mutex_unlock(&simul->mutex.philo_mutex);
	return (flag);
}

void	ft_sleep(t_uint64 time, t_simul *simul)
{
	t_uint64	goal;

	if (time == 0)
	{
		usleep(250);
		return ;
	}
	goal = simul->shared.elapsed_time + time;
	while (simul->shared.elapsed_time != goal
		&& simul->shared.philo_status == LIVE)
		usleep(500);
}

static void	print_purpose(t_simul *simul, int purpose)
{
	if (purpose == THINKING)
		printf(BLUE "is Thinking.\n" RESET);
	else if (purpose == EATING)
		printf(GREEN "is Eating.\n" RESET);
	else if (purpose == SLEEPING)
		printf(MAGENTA "is Sleeping.\n" RESET);
	else if (purpose == FORK)
		printf(GREEN "has taken a Fork.\n" RESET);
	else
	{
		pthread_mutex_lock(&simul->mutex.philo_mutex);
		simul->shared.philo_status = DEAD;
		pthread_mutex_unlock(&simul->mutex.philo_mutex);
		printf(RED "is Died.\n" RESET);
	}
}

void	print_mutex(t_simul *simul, int philo_idx, int purpose)
{
	t_shared	*shared;

	shared = &simul->shared;
	pthread_mutex_lock(&simul->mutex.record);
	if (purpose == EATING)
	{
		pthread_mutex_lock(&simul->mutex.start_mutex[philo_idx]);
		shared->start_time[philo_idx] = shared->elapsed_time;
		pthread_mutex_unlock(&simul->mutex.start_mutex[philo_idx]);
	}
	if (check_philo_died(simul))
	{
		pthread_mutex_unlock(&simul->mutex.record);
		return ;
	}
	printf(YELLOW "%lldms " RESET, shared->elapsed_time);
	printf(CYAN "NO.%d번" RESET "철학자---- ", philo_idx + 1);
	print_purpose(simul, purpose);
	pthread_mutex_unlock(&simul->mutex.record);
}
