/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:45:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 21:41:37 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "execute.h"
#include "libft.h"

int		has_file(char *path, char *filename)
{
	char	*tmp;
	char	*full_path;
	int		fd;

	tmp = ft_strjoin(path, "/");
	if (tmp == NULL)
		exit(1);
	full_path = ft_strjoin(tmp, filename);
	if (full_path == NULL)
		exit(1);
	fd = open(full_path, O_RDONLY);
	if (fd < 0)
	{
		free(full_path);
		return (0);
	}
	free(full_path);
	return (1);
}

int		dup_str(char **env, char *str)
{
	free(*env);
	*env = ft_strdup(str);
	if (*env == NULL)
		return (-1);
	return (1);
}
