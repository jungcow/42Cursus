/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:53:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 23:02:59 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bonus/simulate.h"

void	clear_semaphore(t_simul *simul)
{
	sem_close(simul->sem.forks);
	sem_close(simul->sem.record);
	sem_unlink(simul->fork_name);
	sem_unlink(simul->record_name);
}

void	clear_simulation(t_simul *simul)
{
	clear_semaphore(simul);
	free(simul);
}
