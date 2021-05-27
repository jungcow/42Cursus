/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:58:24 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 17:05:21 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "execute.h"

#include "libft.h"
#include <stdio.h>
int		create_pipeline(int *fd, int idx)
{
//	fd[READ] = open("/dev/tty", O_RDONLY);
//	fd[WRITE] = open("/dev/tty", O_WRONLY);
	fd[READ] = 3 + idx * 2;
	fd[WRITE] = 4 + idx * 2;
	dup2(0, fd[READ]);
	dup2(1, fd[WRITE]);
	close(0);
	close(1);
	printf("check fd: %d, %d\n", fd[READ], fd[WRITE]);
	write(fd[READ], "hello1\n", 7);
	write(fd[READ], ft_itoa(fd[READ]), ft_strlen(ft_itoa(fd[READ])));
	write(fd[WRITE], ft_itoa(fd[WRITE]), ft_strlen(ft_itoa(fd[WRITE])));
	write(fd[WRITE], "hello2\n", 7);
	if (fd[READ] < 0 || fd[WRITE] < 0)
	{
		printf("fd error\n");
		return (-1);
	}
	return (1);
}

int		treat_pipeline(t_execute *execute, int (*fd)[2], int idx)
{
	if (idx + 1 < execute->num)
	{
		if (dup2(fd[NEW][WRITE], STDOUT_FILENO) < 0)
			return (-1);
		close_fds(fd[NEW]);
	}
	if (idx > 0)
	{
		if (dup2(fd[OLD][READ], STDIN_FILENO) < 0)
			return (-1);
		close_fds(fd[OLD]);
	}
	return (1);
}
