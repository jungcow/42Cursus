/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_simulate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:53:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/02 10:58:01 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

void	clear_philosopher(t_philo *philo)
{
	free(philo);
}

void	clear_mutex(t_muex *mutex)
{
	free(mutex.forks);
}

void	clear_shared(t_shared shared)
{
	free(shared->status);
}

void	clear_simulate(t_simul *simul)
{
	clear_philosopher(simul->philo);
	clear_mutex(simul->mutex);
	clear_shared(simul->shaared);
}
