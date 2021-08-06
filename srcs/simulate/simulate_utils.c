/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:32:19 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/07 04:09:44 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"
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

t_uint64	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec + (time.tv_sec * 1000000));
}

void	ft_sleep(t_uint64 time, t_simul *simul)
{
	t_uint64	start;
	t_uint64	micro_time;

	start = get_time();
	micro_time = time * TIME_UNIT;
	while (check_timer_keepgoing(simul, micro_time, start))
		usleep(100);
}

void	print_mutex(t_simul *simul, int philo_idx, int purpose)
{
	int		tmp;

	tmp = simul->shared.elapsed_time;
	pthread_mutex_lock(&simul->mutex.record);
	if (check_philo_died(simul))
	{
		pthread_mutex_unlock(&simul->mutex.record);
		return ;
	}
	printf(YELLOW "%dms " RESET, tmp);
	printf(CYAN "NO.%d번" RESET "철학자---- ", philo_idx + 1);
	if (purpose == THINKING)
		printf(BLUE "is Thinking.\n" RESET);
	else if (purpose == EATING)
		printf(GREEN "is Eating.\n" RESET);
	else if (purpose == SLEEPING)
		printf(MAGENTA "is Sleeping.\n" RESET);
	else if (purpose == FORK)
		printf(GREEN "has taken a Fork.\n" RESET);
	else
		printf(RED "is Died.\n" RESET);
	pthread_mutex_unlock(&simul->mutex.record);
}
