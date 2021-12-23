/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:25:29 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "bonus/utils.h"
#include "bonus/simulate.h"

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
	simul->sem.forks = sem_open(simul->fork_name, O_CREAT, 0600,
			simul->info.philo_num);
	simul->sem.record = sem_open(simul->record_name, O_CREAT, 0600, 1);
	simul->sem.dead = sem_open(simul->dead_name, O_CREAT, 0600, 1);
	if (simul->sem.forks == SEM_FAILED
		|| simul->sem.record == SEM_FAILED
		|| simul->sem.dead == SEM_FAILED)
		return (0);
	sem_unlink(simul->fork_name);
	sem_unlink(simul->record_name);
	sem_unlink(simul->dead_name);
	return (1);
}

int	init_simulation(t_simul *simul, int argc, char **argv)
{
	int	flag;

	flag = true;
	simul->index = 0;
	simul->fork_name = "/sem_fork";
	simul->record_name = "/sem_record";
	simul->dead_name = "/sem_dead";
	simul->elapsed_time = 0;
	simul->start_time = 0;
	simul->philo_status = LIVE;
	simul->simul_status = 0;
	init_info(&simul->info, argc, argv);
	flag = flag && init_semaphore(simul);
	simul->pids = (pid_t *)malloc(sizeof(pid_t) * simul->info.philo_num);
	flag = flag && simul->pids;
	if (flag == false)
		clear_simulation(simul);
	return (flag);
}
