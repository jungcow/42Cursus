/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:01:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/06/06 08:57:29 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "execute.h"

void	wait_process(pid_t *pid, t_execute *execute)
{
	int		i;
	int		status;

	i = 0;
	while (i < execute->num)
	{
		if (waitpid(pid[i], &status, 0) < 0)
		{
			clear_pipeline(execute);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	clear_pipeline(execute);
	free(pid);
}

void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}
