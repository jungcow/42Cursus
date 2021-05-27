/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:39:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 17:01:37 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "execute.h"
#include "libft.h"
#include "error.h"

#include <stdio.h>
int		create_execution(t_execute *execute, int argc, char *argv[])
{
	int		i;

	i = 0;
	while (i + 3 < argc)
	{
		execute->command[i] = ft_split(argv[i], ' ');
		if (execute->command[i] == NULL)
			exit(1);
		i++;
	}
	return (1);
}

int		init_execution(t_execute *execute, int argc, char *argv[])
{
	int		i;

	execute->input = ft_strdup(argv[1]);
	if (execute->input == NULL)
		exit(1);
	execute->output = ft_strdup(argv[argc - 1]);
	if (execute->output == NULL)
	{
		free(execute->input);
		exit(1);
	}
	execute->num = argc - 3;
	execute->command = (char ***)malloc(sizeof(char **) * (execute->num + 1));
	if (execute->command == NULL)
		exit(1);
	i = -1;
	while (++i + 3 < argc)
		execute->command[i] = NULL;
	create_execution(execute, argc, argv + 2);
	return (1);
}

int		execute_child(t_execute *execute, int (*fd)[2], int idx)
{
	if (treat_pipeline(execute, fd, idx) < 0)
		exit(1);
	if (idx == 0)
	{
		input_redirection(execute);
		if (execute->input_fd < 0)
			exit(1);
	}
	else if (idx + 1 == execute->num)
	{
		output_redirection(execute);
		if (execute->output_fd < 0)
			exit(1);
	}
	if (execve(execute->command[idx][0], execute->command[idx], NULL) < 0)
	{
		ft_error_str(COMMAND_ERR, execute->command[idx][0]);
		exit(1);
	}
	if (idx == 0)
		close(execute->input_fd);
	else if (idx + 1 == execute->num)
		close(execute->output_fd);
	exit(0);
}

int		ft_execute(t_execute *execute, char *argv[])
{
	pid_t	pid;
	int		i;
	int		fd[2][2];
	(void)argv;

	i = -1;
	while (++i < execute->num)
	{
		if (create_pipeline(fd[NEW], i) < 0)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			execute_child(execute, fd, i);
		else if (pid > 0 && i > 0)
		{
			printf("i: %d\n", i);
			printf("fd[old]: %d, %d\n", fd[OLD][0], fd[OLD][1]);
			close_fds(fd[OLD]);
		}
		fd[OLD][0] = fd[NEW][0];
		fd[OLD][1] = fd[NEW][1];
	}
	close_fds(fd[OLD]);
	return (1);
}

