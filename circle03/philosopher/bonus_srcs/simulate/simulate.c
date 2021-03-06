/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:55 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 03:44:49 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bonus/simulate.h"

int	simulate(int argc, char **argv)
{
	t_simul	*simul;
	int		ret;

	ret = 0;
	simul = (t_simul *)malloc(sizeof(t_simul));
	if (simul == NULL)
		return (-1);
	if (!init_simulation(simul, argc, argv))
		return (-1);
	ret = exec_simulation(simul);
	clear_simulation(simul);
	return (ret);
}
