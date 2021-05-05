/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 03:49:47 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 05:14:38 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute/execute.h"

int		execute_unit_process(pid_t *process, t_pipeline *pipeline)
{
	t_operation		*operation;

	(void)process;
	operation = &pipeline->operations[0];
	if (is_builtin(operation->argv[0]))
	{
		if (ft_execve(operation->argv[0], operation->argv, g_environ) < 0)
			return (-1);
		return (1);
	}
	if (execute_process(process, pipeline) < 0)
		return (-1);
	return (1);
}
