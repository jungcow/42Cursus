/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:30:37 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/02 11:55:58 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "simulate.h"



void *philosopher(void *param)
{
	t_simul 	*simul;
	int 		index;
	unsigned int num;
	
	simul = (t_simul *)param;
	num = 0;
	while (!is_death && num < simul->info.max_eat_num)
	{
		if (num != 0)
			sleeping();
		while (!is_death && test(index) == 0)
			usleep(TIME_UNIT);
		eating();
		num++;
	}
	return ((void *)NULL);
}

int	init_mutex(t_mutex *mutex, int philo_num)
{
	int	i;
	int	ret;

	i = -1;
	ret = true;
	while (++i < philo_num)
		ret = ret && pthread_mutex_init(&mutex->forks[i], NULL);
	ret = ret && pthread_mutex_init(&mutex->simul_index, NULL);
	return (ret);
}

int	create_thread(t_simul *simul)
{
	int	i;
	int	ret;
	
	i = -1;
	ret = true;
	while (++i < simul->info.philo_num)
	{
		simul->index = i;
		ret = ret && pthread_create(&simul->philo_ids[i], NULL, philosopher, (void *)simul);
		ret = ret && pthrea_create(&simul->timer_ids[i], NULL, timer, (void *)simul);
//		usleep(10);
	}
	return (ret);
}

int	join_thread(t_simul *simul)
{
	int	i;
	int ret;
	int *status;

	i = -1;
	ret = true;
	while (++i < simul->info.philo_num)
	{
		ret = ret && pthread_join(simul->philo_ids[i], (void **)&status);
		ret = ret && pthread_join(simul->timer_ids[i], (void **)&status);
	}
	return (ret);
}

int destroy_mutex(t_mutex *mutex, int philo_num)
{
	int	i;
	int	ret;

	i = -1;
	ret = true;
	while (++i < philo_num)
		ret = ret && pthread_mutex_destroy(&mutex->forks[i]);
	ret = ret && pthread_mutex_destroy(&mutex->simul->index, NULL);
	return (ret);
}

int	exec_simulation(t_simul *simul)
{
	int	ret;

	ret = true;
	ret = ret && init_mutex(&simul->mutex, simul->info.philo_num);
	ret = ret && create_thread(simul);
	ret = ret && join_thread(simul);
	ret = ret && destroy_mutex(&simul->mutex, simul->info.philo_num);
	return (ret);
}
