/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:30:37 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 23:26:45 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "bonus/simulate.h"
#include "bonus/utils.h"

#include <stdio.h>
static int	wait_process(t_simul *simul)
{
	int	i;
	int	status;

	i = 0;
	while (i < simul->info.philo_num)
	{
		if (waitpid(-1, &status, 0) < 0)
			return (-1);
		if ((unsigned int)(status >> 8) == DEAD)
		{
			kill(-1, SIGKILL);
			return (0);
		}
		i++;
	}
	return (0);
}

#include <stdlib.h>
static int	create_process(t_simul *simul)
{
	int	i;

	i = 0;
//	simul->start_time = get_time();
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

	printf("100\n");
	ret = create_process(simul);
	printf("101\n");
	return (ret);
}
