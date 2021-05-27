/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:39:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 13:21:08 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "execute.h"
#include "libft.h"

int		init_execution(t_execute *execute, int argc, char *argv[])
{
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
	return (1);
}

int		treat_pipeline(t_execute *execute)
{


int		input_redirection(t_execute *execute)
{
	close(READ);
	execute->input_fd = open(execute->input, O_RDONLY);
	if (execute->input_fd < 0)
		return (ft_error_str(PERMISSION_ERR, execute->input));
	return (1);
}

int		output_redirection(t_execute *execute)
{
	close(WRITE);
	execute->output_fd = open(execute->output, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (execute->output_fd < 0)
		return (ft_error_str(PERMISSION_ERR, execute->output));
	return (1);
}

int		execute_child(t_execute *execute, char *argv[], int idx)
{
	char	*line;

	if (idx == 0)
		input_redirection(execute);
	else if (idx + 1 == execute->num)
		output-redirection(execute);
	execve(argv[0]);


int		execute(t_execute *execute, char *argv[])
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < execute->num)
	{
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			execute_child(execute, argv, i);
		i++;
	}
	return (1);
}

