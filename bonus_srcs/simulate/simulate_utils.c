/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:32:19 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:35:50 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "bonus/utils.h"
#include "bonus/color.h"
#include "bonus/simulate.h"

t_uint64	get_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(t_uint64 time, t_simul *simul)
{
	t_uint64	goal;

	goal = get_time() + time;
	while (get_time() != goal
		&& simul->philo_status == LIVE)
		usleep(200);
}

static void	print_purpose(t_simul *simul, int purpose)
{
	if (purpose == THINKING)
		printf(BLUE "is Thinking.\n" RESET);
	else if (purpose == EATING)
		printf(GREEN "is Eating.\n" RESET);
	else if (purpose == SLEEPING)
		printf(MAGENTA "is Sleeping.\n" RESET);
	else if (purpose == FORK)
		printf(GREEN "has taken a Fork.\n" RESET);
	else
	{
		sem_wait(simul->sem.dead);
		simul->philo_status = DEAD;
		printf(RED "is Died.\n" RESET);
	}
}

void	print_record(t_simul *simul, int philo_idx, int purpose)
{
	sem_wait(simul->sem.record);
	if (purpose == EATING)
		simul->last_eat_time = get_time();
	if (simul->philo_status == DEAD)
	{
		sem_post(simul->sem.record);
		return ;
	}
	printf(YELLOW "%lldms " RESET, ((get_time() - simul->start_time)));
	printf(CYAN "NO.%d번" RESET "철학자---- ", philo_idx + 1);
	print_purpose(simul, purpose);
	if (purpose != DEAD)
		sem_post(simul->sem.record);
}
