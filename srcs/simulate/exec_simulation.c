/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:30:37 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 23:47:25 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "simulate.h"
#include "utils.h"

static int	init_mutex(t_mutex *mutex, int philo_num)
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

static int	create_thread(t_simul *simul)
{
	int	i;
	int	ret;

	ret = false;
	i = -1;
	while (++i < simul->info.philo_num && !ret)
	{
		ret = ret || pthread_create(&simul->monitor_ids[i],
				NULL, monitoring, (void *)simul);
		ret = ret || pthread_create(&simul->philo_ids[i],
				NULL, philosopher, (void *)simul);
	}
	if (!ret)
		simul->shared.clock_status = CLOCK_START;
	else
	{
		pthread_mutex_lock(&simul->mutex.philo_mutex);
		simul->shared.philo_status = DEAD;
		pthread_mutex_unlock(&simul->mutex.philo_mutex);
		simul->shared.clock_status = CLOCK_TERMINATE;
	}
	return (ret * 100);
}

static int	join_thread(t_simul *simul)
{
	int	i;
	int	ret;
	int	*status;

	i = -1;
	ret = false;
	while (++i < simul->info.philo_num)
	{
		ret = ret || pthread_join(simul->philo_ids[i], (void **)&status);
		ret = ret || pthread_join(simul->monitor_ids[i], (void **)&status);
	}
	return (ret * 10000);
}

static int	destroy_mutex(t_mutex *mutex, int philo_num)
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
	return (ret * 1000000);
}

int	exec_simulation(t_simul *simul)
{
	int	ret;
	int	flag;
	int	exit_flag;

	ret = false;
	flag = 0;
	exit_flag = 0;
	ret = ret || (flag = init_mutex(&simul->mutex, simul->info.philo_num));
	ret = ret || (flag = create_thread(simul));
	if (flag)
		exit_flag = flag;
	ret = (flag = join_thread(simul));
	if (exit_flag)
		return (exit_flag);
	ret = ret || (flag = destroy_mutex(&simul->mutex, simul->info.philo_num));
	return (flag);
}
