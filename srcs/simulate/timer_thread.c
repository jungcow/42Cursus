/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:46:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 03:06:31 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
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

void	*elapsed_timer(void *param)
{
	t_shared	*shared;
	t_simul		*simul;
	t_uint64	start;

	simul = (t_simul *)param;
	shared = &simul->shared;
	while (shared->clock_status != CLOCK_START)
		;
	start = get_time();
	while (check_elapsed_timer(simul))
		shared->elapsed_time = (get_time() - start) / TIME_UNIT;
//	pthread_mutex_lock(&simul->mutex.record);
	printf("CLOCK 종료\n");
//	pthread_mutex_unlock(&simul->mutex.record);
	return ((void *)NULL);
}

int	death_timer(t_uint64 time, t_simul *simul, t_philo *philo)
{
	t_uint64	start;

	start = get_time();
	while (check_timer_keepgoing(simul, time, start))
	{
		if (check_death_timer_off(simul, philo))
		{
			pthread_mutex_lock(&simul->mutex.confirm_mutex[philo->index]);
			simul->shared.confirmed[philo->index] = CONFIRMED;
			pthread_mutex_unlock(&simul->mutex.confirm_mutex[philo->index]);
		//	printf("%lldms 휴 살았다.\n", get_time());
			return (1);
		}
	}
	// 죽음의 구렁텅이
	return (0);
}

void	*monitoring(void *param)
{
	t_simul *simul;
	t_philo	philo;

	simul = (t_simul *)param;
	pthread_mutex_lock(&simul->mutex.monitor_id_mutex);
	philo = simul->philo[simul->monitor_index];
	philo.index = simul->monitor_index;
	simul->monitor_index++;
	pthread_mutex_unlock(&simul->mutex.monitor_id_mutex);
	while (simul->shared.clock_status == 0)
		;
	while (check_monitoring(simul, &philo))
	{
		if (check_death_timer_on(simul, &philo))
		{
			if (!death_timer(simul->info.time_to_die * TIME_UNIT, simul, &philo))
			{
				pthread_mutex_lock(&simul->mutex.philo_mutex);
				simul->shared.philo_status = DEAD;
				pthread_mutex_unlock(&simul->mutex.philo_mutex);
//				pthread_mutex_lock(&simul->mutex.record);
				printf("MONITOR: %dms, %d번 철학자- 죽음\n", simul->shared.elapsed_time, philo.index + 1);
//				pthread_mutex_unlock(&simul->mutex.record);
				return ((void *)NULL);
			}
			else
				usleep(50);
		}
	}
	printf("%d번 모니터 종료\n", philo.index + 1);
	return ((void *)NULL);
}

