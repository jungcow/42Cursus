/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 12:46:10 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "simulate.h"

#include <stdio.h>
void	init_info(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->max_eat_num = UNSIGNED_INT_MAX + 1;
	if (argc == 6)
		info->max_eat_num = ft_atoi(argv[5]);
	printf("num: %d\n", info->philo_num);
	printf("die: %lld\n", info->time_to_die);
	printf("eat: %lld\n", info->time_to_eat);
	printf("sleep: %lld\n", info->time_to_sleep);
}

int	init_philosopher(t_philo **philo, int philo_num)
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

int	init_mutex_var(t_mutex *mutex, int philo_num)
{
	mutex->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	mutex->timer_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	mutex->confirm_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	if (!mutex->forks || !mutex->timer_mutex || !mutex->confirm_mutex)
		return (0);
	return (1);
}

int	init_shared_data(t_shared *shared, int philo_num)
{
	int	i;

	shared->timer_status = (int *)malloc(sizeof(int) * philo_num);
	shared->confirmed = (int *)malloc(sizeof(int) * philo_num);
	shared->start = (t_uint64 *)malloc(sizeof(t_uint64) * philo_num);
	if (shared->timer_status == NULL || shared->confirmed == NULL)
//		|| shared->start == NULL)
	{
		printf("할당 안됨?\n");
		return (0);
	}
	i = -1;
	while (++i < philo_num)
	{
		shared->timer_status[i] = DEATH_TIMER_OFF;
		shared->confirmed[i] = NOT_CONFIRMED;
		shared->start[i] = 0;
	}
	shared->simul_num = 0;
	shared->elapsed_time = 0;
	shared->philo_status = LIVE;
	shared->clock_status = CLOCK_NOT_START;
	return (1);
}

int	init_simulation(t_simul *simul, int argc, char **argv)
{
	int	flag;

	simul->index = 0;
	simul->monitor_index = 0;
	init_info(&simul->info, argc, argv);
	flag = true;
	flag = flag
		&& (simul->philo_ids = (pthread_t *)malloc(sizeof(pthread_t)
				* simul->info.philo_num));
	flag = flag
		&& (simul->monitor_ids = (pthread_t *)malloc(sizeof(pthread_t)
				* simul->info.philo_num));
	flag = flag && init_philosopher(&simul->philo, simul->info.philo_num);
	flag = flag && init_mutex_var(&simul->mutex, simul->info.philo_num);
	flag = flag && init_shared_data(&simul->shared, simul->info.philo_num);
	if (flag == false)
		clear_simulation(simul);
	return (flag);
}
