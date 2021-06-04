/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:58:24 by jungwkim          #+#    #+#             */
/*   Updated: 2021/06/03 13:03:28 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "execute.h"
#include "libft.h"

#include <stdio.h>
int		ft_pipe(int *fd, int i)
{
	char	*index;
	char	*path;

	index = ft_itoa(i);
	path = ft_strjoin("./.pipe/", index);
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

void	remove_pipeline(int i)
{
	char	*path;
	char	*index;
	char	*argv[4];

	argv[0] = "/bin/rm";
	argv[1] = "-rf";
	argv[3] = NULL;
	index = ft_itoa(i);
	path = ft_strjoin("./.pipe/", index);
	free(index);
	if (path == NULL)
		exit(EXIT_FAILURE);
	argv[2] = path;
	if (execve(argv[0], argv, NULL) < 0)
		exit(EXIT_FAILURE);
	free(path);
	exit(EXIT_SUCCESS);
}

void	clear_pipeline(t_execute *execute)
{
	int		i;
	pid_t	*pid;

	i = 0;
	pid = (pid_t *)malloc(sizeof(pid_t) * execute->num);
	while (i < execute->num)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			remove_pipeline(i);
		i++;
	}
}
