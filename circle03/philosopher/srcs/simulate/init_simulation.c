/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 16:48:08 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "simulate.h"

static void	init_info(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->max_eat_num = UNSIGNED_INT_MAX + 1;
	if (argc == 6)
		info->max_eat_num = ft_atoi(argv[5]);
}

static int	init_philosopher(t_philo **philo, int philo_num)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * philo_num);
	if (*philo == NULL)
		return (0);
	i = 0;
	while (i < philo_num)
	{
		(*philo)[i].lfork = i;
		(*philo)[i].rfork = i + 1;
		if (i == philo_num - 1)
			(*philo)[i].rfork = 0;
		i++;
	}
	return (1);
}

static int	init_mutex_var(t_mutex *mutex, int philo_num)
{
	mutex->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo_num);
	mutex->start_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo_num);
	mutex->simul_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo_num);
	if (!mutex->forks || !mutex->simul_mutex || !mutex->start_mutex)
		return (0);
	return (1);
}

static int	init_shared_data(t_shared *shared, int philo_num)
{
	int	i;

	shared->start_time = (t_uint64 *)malloc(sizeof(t_uint64) * philo_num);
	shared->simul_status = (int *)malloc(sizeof(int) * philo_num);
	if (!shared->start_time || !shared->simul_status)
		return (0);
	i = -1;
	while (++i < philo_num)
	{
		shared->start_time[i] = 0;
		shared->simul_status[i] = 0;
	}
	shared->philo_status = LIVE;
	shared->clock_status = CLOCK_NOT_START;
	shared->elapsed_time = 0;
	return (1);
}

int	init_simulation(t_simul *simul, int argc, char **argv)
{
	int	flag;

	simul->index = 0;
	simul->monitor_index = 0;
	init_info(&simul->info, argc, argv);
	flag = true;
	simul->philo_ids = (pthread_t *)malloc(sizeof(pthread_t)
			* simul->info.philo_num);
	simul->monitor_ids = (pthread_t *)malloc(sizeof(pthread_t)
			* simul->info.philo_num);
	flag = flag && simul->philo_ids;
	flag = flag && simul->monitor_ids;
	flag = flag && init_philosopher(&simul->philo, simul->info.philo_num);
	flag = flag && init_mutex_var(&simul->mutex, simul->info.philo_num);
	flag = flag && init_shared_data(&simul->shared, simul->info.philo_num);
	if (flag == false)
		clear_simulation(simul);
	return (flag);
}
