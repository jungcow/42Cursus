/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:58:24 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 19:05:54 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "execute.h"
#include "libft.h"

int		ft_pipe(int *fd, int i)
{
	char	*index;

	index = ft_itoa(i);
	fd[0] = open(index, O_CREAT | O_RDONLY, 0644);
	fd[1] = open(index, O_CREAT | O_WRONLY, 0644);
	if (fd[0] < 0 || fd[1] < 0)
	{
		free(index);
		return (-1);
	}
	free(index);
	return (1);
}

int		treat_pipeline(t_execute *execute, int *new_fd, int *old_fd, int idx)
{
	if (idx + 1 < execute->num)
	{
		if (dup2(new_fd[WRITE], STDOUT_FILENO) < 0)
			return (-1);
		close_fds(new_fd);
	}
	if (idx > 0)
	{
		if (dup2(old_fd[READ], STDIN_FILENO) < 0)
			return (-1);
		close_fds(old_fd);
	}
	return (1);
}
