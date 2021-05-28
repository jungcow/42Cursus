/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:58:24 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 21:47:53 by jungwkim         ###   ########.fr       */
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
	char	*path;

	index = ft_itoa(i);
	path = ft_strjoin("./pipe/", index);
	free(index);
	if (path == NULL)
		exit(1);
	fd[0] = open(path, O_CREAT | O_RDONLY, 0644);
	fd[1] = open(path, O_CREAT | O_WRONLY, 0644);
	if (fd[0] < 0 || fd[1] < 0)
	{
		free(path);
		return (-1);
	}
	free(path);
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
