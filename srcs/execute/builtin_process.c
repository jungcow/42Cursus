/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 04:23:28 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/07 18:15:19 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute/execute.h"
#include "builtin.h"
#include "libft.h"

int		is_builtin(char *command)
{
	char	*builtin[8];
	int		i;

	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "export";
	builtin[4] = "unset";
	builtin[5] = "env";
	builtin[6] = "exit";
	builtin[7] = NULL;
	i = 0;
	while (builtin[i])
	{
		if (ft_strcmp(command, builtin[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_execve(char *command, char **argv, char **env)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (ft_strcmp(command, "echo") == 0)
		ret = ft_echo(ft_strslen(argv), argv, env);
	else if (ft_strcmp(command, "cd") == 0)
		ret = ft_cd(ft_strslen(argv), argv, env);
	else if (ft_strcmp(command, "pwd") == 0)
		ret = ft_pwd();
	else if (ft_strcmp(command, "env") == 0)
		ret = ft_env(ft_strslen(argv), argv, env);
	else if (ft_strcmp(command, "export") == 0)
		ret = ft_export(ft_strslen(argv), argv, env);
	/*
	else if (ft_strcmp(command, "unset") == 0)
		ret = ft_envset(ft_strslen(argv), argv);
	*/
	else if (ft_strcmp(command, "exit") == 0)
		ret = ft_exit(ft_strslen(argv), argv);
	return (ret);
}
