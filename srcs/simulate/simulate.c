/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 00:05:24 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "simulate.h"

#include <unistd.h>
#include <stdio.h>

/*
void	check_all_philo_terminated(t_simul *simul)
{
	while (1)
	{
		i = 0;
		while (i < simul->info.philo_num)
		{
			if (simul->shared.timer_status[ != SIMUL_DONE)
				break ;
			i++;
		}
	}
}
*/


int	simulate(int argc, char **argv)
{
	t_simul	*simul;
//	t_simul_wrap	wrapper;
	int		ret;

	//wrapper.index = -1;
	simul = (t_simul *)malloc(sizeof(t_simul));
	if (simul == NULL)
		return (-1);
	if (!init_simulation(simul, argc, argv))
		return (-1);
	ret = exec_simulation(simul);
//	sleep(8);
//	check_all_philo_terminated(simul);
	clear_simulation(simul);
	if (ret)
		return (ret);
	return (0);
}
