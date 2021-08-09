/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 23:24:57 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bonus/simulate.h"

#include <stdio.h>
int	simulate(int argc, char **argv)
{
	t_simul	*simul;
	int		ret;

	ret = 0;
	simul = (t_simul *)malloc(sizeof(t_simul));
	printf("1\n");
	if (simul == NULL)
		return (-1);
	printf("2\n");
	if (!init_simulation(simul, argc, argv))
		return (-1);
	printf("3\n");
	ret = exec_simulation(simul);
	printf("4\n");
	clear_simulation(simul);
	printf("5\n");
	return (ret);
}
