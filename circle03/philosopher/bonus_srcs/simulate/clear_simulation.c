/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:53:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:17:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bonus/simulate.h"

void	clear_semaphore(t_simul *simul)
{
	sem_close(simul->sem.forks);
	sem_close(simul->sem.record);
	sem_close(simul->sem.dead);
}

void	clear_simulation(t_simul *simul)
{
	clear_semaphore(simul);
	free(simul->pids);
	free(simul);
}
