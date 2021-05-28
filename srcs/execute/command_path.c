/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:32:32 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 21:58:52 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "execute.h"
#include "error.h"
#include "libft.h"

int		check_path_type(char *command)
{
	if (*command == '/')
		return (*command);
	if (*command == '.')
		return (*command);
	return (0);
}

int		join_path(char **dir, char *filename)
{
	*dir = ft_strjoin(*dir, "/");
	if (*dir == NULL)
		return (-1);
	*dir = ft_strjoin(*dir, filename);
	if (*dir == NULL)
		return (-1);
	return (1);
}

int		check_path_env(char *filename, char **dir, char *envp[])
{
	char	**path;
	int		i;
	char	*value;

	value = get_environ("PATH", envp);
	if (value == NULL)
		return (NO_FILE);
	path = ft_split(value, ':');
	free(value);
	if (path == NULL)
		return (-1);
	i = -1;
	while (path[++i])
		if (has_file(path[i], filename))
			break ;
	if (path[i] == NULL)
	{
		ft_strsfree(path);
		return (0);
	}
	if ((dup_str(dir, path[i]) < 0) || (join_path(dir, filename) < 0))
		return (-1);
	ft_strsfree(path);
	return (1);
}

int		check_path(char *command, char **dir)
{
	int			ret;

	ret = open(command, O_RDONLY);
	if (ret < 0)
		return (0);
	*dir = command;
	return (1);
}

int		get_path(char *filename, char **dir, char *envp[])
{
	int		ret;

	ret = 1;
	*dir = NULL;
	if (check_path_type(filename) == 0)
		ret = check_path_env(filename, dir, envp);
	else if (check_path_type(filename) == '/')
		ret = check_path(filename, dir);
	else if (check_path_type(filename) == '.')
		ret = check_path(filename, dir);
	if (ret == 0 || ret == NO_FILE)
	{
		if (ret == 0)
			ft_error_str(COMMAND_ERR, filename);
		else if (ret == NO_FILE)
			ft_error_str(NO_FILE_ERR, filename);
		return (1);
	}
	else if (ret == -1)
		return (-1);
	return (0);
}
