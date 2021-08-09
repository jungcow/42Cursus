/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:44:31 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 23:39:15 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bonus/simulate.h"

#include <stdio.h>
int	open_semaphore(t_simul *simul)
{
	simul->sem.forks = sem_open(simul->fork_name, O_CREAT, 0644, 5);
	simul->sem.record = sem_open(simul->record_name, O_CREAT, 0644, 1);
	if (simul->sem.forks == SEM_FAILED || simul->sem.record == SEM_FAILED)
		return (1);
	return (0);
}

//pthread create & join 에러처리 하기
int	create_monitor(t_simul *simul)
{
	pthread_t	tid;
	int			ret;
	int			*status;

	ret = 0;
	ret = pthread_create(&tid, NULL, monitoring, (void *)simul);
	if (ret != 0)
		return (ret);
	printf("ret: %d\n", ret);
	ret = pthread_join(tid, (void **)&status);
	return (ret);
}

static void	take_fork(t_simul *simul, int mode)
{
	if (mode == TAKE)
	{
		sem_wait(simul->sem.forks);
		sem_wait(simul->sem.forks);
	}
	else if (mode == PUT)
	{
		sem_post(simul->sem.forks);
		sem_post(simul->sem.forks);
	}
}

static int	eating(t_simul *simul)
{
	take_fork(simul, TAKE);
	print_record(simul, simul->index, FORK);
	print_record(simul, simul->index, EATING);
	ft_sleep(simul->info.time_to_eat, simul);
	if (simul->philo_status == DEAD)
		return (DEAD);
	return (0);
}

static int	sleeping(t_simul *simul)
{
	print_record(simul, simul->index, SLEEPING);
	ft_sleep(simul->info.time_to_sleep, simul);
	if (simul->philo_status == DEAD)
		return (DEAD);
	return (0);
}

int	start_simulation(t_simul *simul)
{
	unsigned int	num;

	num = -1;
	simul->start_time = 0;
	while (++num < simul->info.max_eat_num)
	{
		if (num != 0)
			if (simul->philo_status == DEAD || sleeping(simul))
				return (1);
		print_record(simul, simul->index, THINKING);
		if (num == 0 && (simul->index + 1) % 2 == 0)
			ft_sleep(simul->info.time_to_eat / 2, simul);
		if (simul->philo_status == DEAD || eating(simul))
			return (1);
	}
	simul->simul_status = DONE;
	return (0);
}

static void	close_semaphore(t_simul *simul)
{
	sem_close(simul->sem.record);
	sem_close(simul->sem.forks);
}

//pthread create & join 에러처리 하기
int	philosopher(t_simul *simul)
{
	int			ret;

	printf("1000\n");
	ret = false;
	ret = ret || open_semaphore(simul);
	printf("1001\n");
	ret = ret || create_monitor(simul);
	printf("1002\n");
//	ret = ret || start_simulation(simul);
	printf("1003\n");
	close_semaphore(simul);
	printf("1004\n");
	exit(0);
}
