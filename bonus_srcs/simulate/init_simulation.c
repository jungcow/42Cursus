/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 23:21:00 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "bonus/utils.h"
#include "bonus/simulate.h"

#include <stdio.h>
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

static int	init_semaphore(t_simul *simul)
{
	printf("20\n");
	simul->sem.forks = sem_open(simul->fork_name, O_CREAT, 0644, 5);
	simul->sem.record = sem_open(simul->record_name, O_CREAT, 0644, 1);
	printf("21\n");
	if (simul->sem.forks == SEM_FAILED || simul->sem.record == SEM_FAILED)
		return (0);
	printf("22\n");
	sem_close(simul->sem.forks);
	sem_close(simul->sem.record);
	printf("23\n");
	return (1);
}

int	init_simulation(t_simul *simul, int argc, char **argv)
{
	int	flag;

	printf("10\n");
	flag = true;
	simul->index = 0;
	simul->fork_name = "/sem_fork";
	simul->record_name = "/sem_record";
	simul->elapsed_time = 0;
	simul->start_time = 0;
	simul->philo_status = LIVE;
	simul->simul_status = 0;
	init_info(&simul->info, argc, argv);
	printf("11\n");
	flag = flag && init_semaphore(simul);
	printf("12\n");
	simul->pids = (pid_t *)malloc(sizeof(pid_t) * simul->info.philo_num);
	printf("13\n");
	flag = flag && simul->pids;
	if (flag == false)
		clear_simulation(simul);
	printf("14\n");
	return (flag);
}
