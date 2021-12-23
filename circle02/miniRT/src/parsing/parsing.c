/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 02:48:17 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 09:02:44 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parsing.h"

int			check_filename(char *filename)
{
	int		len;

	len = ft_strlen(filename);
	if (len < 3)
		return (0);
	if (filename[len - 1] != 't' ||
			filename[len - 2] != 'r' ||
			filename[len - 3] != '.')
		return (0);
	return (1);
}

static int	create_info(t_info **info, char *line)
{
	t_info *new_info;

	if (!line || !(*line))
		return (1);
	if (!(*info))
	{
		new_info = NULL;
		if (!(*info = (t_info *)malloc(sizeof(t_info))))
			return (0);
		if (!((*info)->elem = ft_split(line, ' ')))
			return (0);
		(*info)->next = NULL;
	}
	else
	{
		if (!(new_info = (t_info *)malloc(sizeof(t_info))))
			return (0);
		if (!(new_info->elem = ft_split(line, ' ')))
			return (0);
		new_info->next = (*info);
		(*info) = new_info;
	}
	return (1);
}

void		clear_info(t_info **info)
{
	t_info	*tmp;

	while (*info)
	{
		clear_strs(&((*info)->elem));
		tmp = *info;
		(*info) = (*info)->next;
		free(tmp);
	}
}

static int	validate_info(t_info *info)
{
	if (!validate_identifier(info))
		return (0);
	while (info)
	{
		if (!validate_others(info->elem, info->elem[0]))
			return (0);
		info = info->next;
	}
	return (1);
}

t_info		*parsing(char *filename)
{
	int		fd;
	int		ret;
	char	*line;
	t_info	*info;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	info = NULL;
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (!create_info(&info, line))
		{
			clear_info(&info);
			return (NULL);
		}
		free(line);
		if (ret == 0)
			break ;
	}
	if (!validate_info(info))
	{
		clear_info(&info);
		return (NULL);
	}
	return (info);
}
