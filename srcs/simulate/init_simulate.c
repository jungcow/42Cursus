/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/02 11:44:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "simulate.h"

void	init_info(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->max_eat_num = UNSIGNED_INT_MAX + 1;
	if (argc == 6)
		info->max_eat_num = ft_atoi(argv[5]);
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
		pihlo[i]->lfork = i % philo_num;
		pihlo[i]->rfork = i % philo_num + 1;
		if (i == philo_num - 1)
			philo[i]->rfork = 0;
		i++;
	}
	return (1);
}

int	init_forks(pthread_mutex_t **forks, int philo_num)
{
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	if (*forks == NULL)
		return (0);
	return (1);
}

int	init_shared_data(t_shared *shared, int philo_num)
{
	shared->status = (int *)malloc(sizeof(int) * philo_num);
	if (shared->status == NULL)
		return (0);
	shared->simul_num = 1;
	shared->elapsed_time = 0;
	shared->is_death = 0;
	return (1);
}

int	init_simulation(t_simul *simul, int argc, char **argv)
{
	int	flag;

	init_info(&simul->info, argc, argv);
	flag = true;
	flag = flag
		&& (simul->philo_ids = (pthread_t *)malloc(sizeof(pthread_t)
				* simul->info.philo_num));
	flag = flag
		&& (simul->timer_ids = (pthread_t *)malloc(sizeof(pthread_t)
				* simul->info.philo_num));
	flag = flag && init_philosopher(&simul->philo, simul->info.philo_num);
	flag = flag && init_forks(&simul->mutex.forks, simul->info.philo_num);
	flag = flag && init_shared_data(&simul->shared, simul->info.philo_num);
	if (flag == false)
		clear_simulation(simul);
	return (flag);
}
