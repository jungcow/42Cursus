/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:39:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/06/06 08:57:55 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "execute.h"
#include "libft.h"
#include "error.h"

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

int		execute_child(t_execute *execute, char *envp[], int (*fd)[2], int idx)
{
	char	***command;
	char	*dir;

	command = execute->command;
	if (get_path(execute->command[idx][0], &dir, envp) < 0)
		exit(EXIT_FAILURE);
	if (treat_pipeline(execute, fd[NEW], fd[OLD], idx) < 0)
		exit(1);
	if (idx == 0)
		input_redirection(execute);
	if (idx + 1 == execute->num)
		output_redirection(execute);
	if (execve(dir, command[idx], NULL) < 0)
		exit(EXIT_FAILURE);
	if (idx == 0)
		close(execute->input_fd);
	else if (idx + 1 == execute->num)
		close(execute->output_fd);
	exit(0);
}

int		ft_execute(t_execute *execute, char *envp[])
{
	pid_t	*pid;
	int		i;
	int		fd[2][2];

	i = -1;
	pid = (pid_t *)malloc(sizeof(pid_t) * execute->num);
	while (++i < execute->num)
	{
		if (ft_pipe(fd[NEW], i) < 0)
			exit(EXIT_FAILURE);
		pid[i] = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		else if (pid[i] == 0)
			execute_child(execute, envp, fd, i);
		else if (pid[i] > 0 && i > 0)
			close_fds(fd[OLD]);
		fd[OLD][0] = fd[NEW][0];
		fd[OLD][1] = fd[NEW][1];
	}
	close_fds(fd[OLD]);
	wait_process(pid, execute);
	return (1);
}

void	clear_execution(t_execute *execute)
{
	int		i;

	free(execute->input);
	free(execute->output);
	i = -1;
	while (execute->command[++i])
		ft_strsfree(execute->command[i]);
}
