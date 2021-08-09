/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:32:19 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 23:00:58 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "bonus/utils.h"
#include "bonus/color.h"
#include "bonus/simulate.h"

t_uint64	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
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
*/

void	ft_sleep(t_uint64 time, t_simul *simul)
{
	t_uint64	goal;

	goal = simul->elapsed_time + time;
	while (simul->elapsed_time != goal
		&& simul->philo_status == LIVE)
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
		simul->philo_status = DEAD;
		printf(RED "is Died.\n" RESET);
	}
}

void	print_record(t_simul *simul, int philo_idx, int purpose)
{
	sem_wait(simul->sem.record);
	if (purpose == EATING)
		simul->start_time = simul->elapsed_time;
	if (simul->philo_status == DEAD)
	{
		sem_post(simul->sem.record);
		return ;
	}
	printf(YELLOW "%lldms " RESET, simul->elapsed_time);
	printf(CYAN "NO.%d번" RESET "철학자---- ", philo_idx + 1);
	print_purpose(simul, purpose);
	sem_post(simul->sem.record);
}
