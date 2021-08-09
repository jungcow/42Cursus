/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:30:37 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:26:17 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "bonus/simulate.h"
#include "bonus/utils.h"

static int	wait_process(t_simul *simul)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (i < simul->info.philo_num)
	{
		if (waitpid(-1, &status, 0) < 0)
			return (-1);
		if ((unsigned int)(status >> 8) == 1)
		{
			j = simul->info.philo_num;
			while (j--)
				kill(simul->pids[j], SIGKILL);
			return (0);
		}
		else if ((unsigned int)(status >> 8) == 255)
			return (-1);
		i++;
	}
	return (0);
}

static int	create_process(t_simul *simul)
{
	int	i;

	i = 0;
	simul->start_time = get_time();
	simul->last_eat_time = simul->start_time;
	while (i < simul->info.philo_num)
	{
		simul->pids[i] = fork();
		if (simul->pids[i] < 0)
			return (-1);
		if (simul->pids[i] == 0)
		{
			simul->index = i;
			philosopher(simul);
		}
		i++;
	}
	if (wait_process(simul) < 0)
		return (-1);
	return (0);
}

int	exec_simulation(t_simul *simul)
{
	int	ret;

	ret = create_process(simul);
	return (ret);
}
