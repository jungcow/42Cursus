/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:30:37 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 12:42:35 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "simulate.h"
#include "utils.h"

#include <stdio.h>
int	init_mutex(t_mutex *mutex, int philo_num)
{
	int	i;
	int	ret;

	i = -1;
	ret = false;
	while (++i < philo_num)
	{
		ret = ret || pthread_mutex_init(&mutex->forks[i], NULL);
		ret = ret || pthread_mutex_init(&mutex->timer_mutex[i], NULL);
		ret = ret || pthread_mutex_init(&mutex->confirm_mutex[i], NULL);
	}
	ret = ret || pthread_mutex_init(&mutex->philo_mutex, NULL);
	ret = ret || pthread_mutex_init(&mutex->clock_mutex, NULL);
	ret = ret || pthread_mutex_init(&mutex->philo_id_mutex, NULL);
	ret = ret || pthread_mutex_init(&mutex->monitor_id_mutex, NULL);
	ret = ret || pthread_mutex_init(&mutex->simul_num_mutex, NULL);
	ret = ret || pthread_mutex_init(&mutex->record, NULL);
	return (ret);
}

int	create_thread(t_simul *simul)
{
	int	i;
	int	ret;
	
	ret = false;
//	ret = ret || pthread_create(&simul->clock_id, NULL, elapsed_timer, (void *)simul);
	i = -1;
	while (++i < simul->info.philo_num && !ret)
	{
		ret = ret || pthread_create(&simul->monitor_ids[i], NULL, monitoring, (void *)simul);
		ret = ret || pthread_create(&simul->philo_ids[i], NULL, philosopher, (void *)simul);
	}
	if (!ret)
		simul->shared.clock_status = CLOCK_START;
	else
	{
		simul->shared.philo_status = DEAD;
		simul->shared.clock_status = CLOCK_TERMINATE;
	}
	return (ret * 10);
}

int	join_thread(t_simul *simul)
{
	int	i;
	int ret;
	int *status;

	i = -1;
	ret = false;
	while (++i < simul->info.philo_num)
	{
		ret = ret || pthread_join(simul->philo_ids[i], (void **)&status);
		ret = ret || pthread_join(simul->monitor_ids[i], (void **)&status);
	}
	simul->shared.clock_status = CLOCK_TERMINATE;
//	ret = ret || pthread_join(simul->clock_id, (void **)&status);
	if (ret)
	{
		write(1, "Pthread Join Error\n", ft_strlen("Pthread Join Error\n"));
		printf("ret: %d\n", ret);
	}
	return (ret * 100);
}

int destroy_mutex(t_mutex *mutex, int philo_num)
{
	int	i;
	int	ret;

	i = -1;
	ret = false;
	while (++i < philo_num)
	{
		ret = ret || pthread_mutex_destroy(&mutex->forks[i]);
		ret = ret || pthread_mutex_destroy(&mutex->timer_mutex[i]);
		ret = ret || pthread_mutex_destroy(&mutex->confirm_mutex[i]);
	}
	ret = ret || pthread_mutex_destroy(&mutex->simul_num_mutex);
	ret = ret || pthread_mutex_destroy(&mutex->record);
	ret = ret || pthread_mutex_destroy(&mutex->philo_mutex);
	ret = ret || pthread_mutex_destroy(&mutex->clock_mutex);
	ret = ret || pthread_mutex_destroy(&mutex->philo_id_mutex);
	ret = ret || pthread_mutex_destroy(&mutex->monitor_id_mutex);
	if (ret)
	{
		write(1, "Mutex Destroy Error\n", ft_strlen("Mutex Destroy Error\n"));
	}
	return (ret * 1000);
}

int	exec_simulation(t_simul *simul)
{
	int	ret;

	ret = false;
	printf("exec\n");
	ret = ret || init_mutex(&simul->mutex, simul->info.philo_num);
	ret = ret || create_thread(simul);
	ret = ret || join_thread(simul);
	ret = ret || destroy_mutex(&simul->mutex, simul->info.philo_num);
	printf("ret: %d\n", ret);
	return (ret);
}
