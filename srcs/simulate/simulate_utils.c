/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jungwkim <jungwkim@student.42seoul.kr>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/04 15:45:05 by jungwkim		  #+#	#+#			 */
/*   Updated: 2021/08/04 18:02:36 by jungwkim         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <sys/time.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils.h"
#include "simulate.h"

t_uint64		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec + (time.tv_sec * 1000000));
}

void	ft_sleep(t_uint64 time, t_simul *simul)
{
	t_uint64	start;

	start = get_time();
	while (check_timer_keepgoing(simul, time, start))
		;
}

t_uint64	get_elapsed_time(t_uint64 start_time)
{
	t_uint64	time;

	time = (get_time() - start_time) / TIME_UNIT;
	return (time);
}

void	print_mutex(t_simul *simul, int philo_idx, int purpose)
{
	t_uint64	tmp;

	tmp = get_time();
	pthread_mutex_lock(&simul->mutex.record);
	printf(YELLOW    "%lldms "   RESET, get_elapsed_time(simul->shared.start[philo_idx]));
	printf(CYAN "NO.%d번" RESET "철학자---- ", philo_idx + 1);
	if (purpose == THINKING)
		printf(BLUE "Thinking.\n" RESET);
	else if (purpose == EATING)
		printf(GREEN "Eating.\n" RESET);
	else if (purpose == SLEEPING)
		printf(MAGENTA "Sleeping.\n" RESET);
	else
		printf(RED "Dead.\n" RESET);
	pthread_mutex_unlock(&simul->mutex.record);
//	simul->shared.start[philo_idx] += get_time() - tmp;
}
