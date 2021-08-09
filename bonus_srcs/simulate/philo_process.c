/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:44:31 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:30:28 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bonus/error.h"
#include "bonus/simulate.h"

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
	take_fork(simul, PUT);
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

static int	start_simulation(t_simul *simul)
{
	unsigned int	num;

	num = -1;
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

int	philosopher(t_simul *simul)
{
	int			ret;
	int			*status;
	pthread_t	tid;

	ret = false;
	ret = pthread_create(&tid, NULL, monitoring, (void *)simul);
	if (ret)
		show_error(ret * 100);
	ret = ret || start_simulation(simul);
	ret = pthread_join(tid, (void **)&status);
	if (ret)
		show_error(ret * 10000);
	ret = false;
	ret = ret || sem_close(simul->sem.forks);
	ret = ret || sem_close(simul->sem.record);
	ret = ret || sem_close(simul->sem.dead);
	if (ret)
		exit(-1);
	exit(0);
}
