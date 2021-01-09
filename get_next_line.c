/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:31:02 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/06 20:03:24 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buffer(char *buffer)
{
	ssize_t		i;
	int			flag;

	i = 0;
	while (i++ < BUFFER_SIZE)
		if (buffer[i] == '\n' || buffer[i] == 4)
		{
			//flag = (buffer[i] == '\n') ? i : 0;
			return (i);
		}
	return (-1);
}

char	*strdup_buffer(char *s1, char *s2, ssize_t len)
{
	s1 = ft_strdup(s2, len);
	if (!s1)
	{
		free(s2);
		return (0);
	}
	free(s2);
	return (s1);
}

int		read_buffer(int fd, char *buffer, char *backup, char **line)
{
	char			*tmp;
	ssize_t			len;
	static ssize_t	len_sum;
	int				flag;
	
	len_sum = 0;
	while ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (len < 0)
		{
			if (len_sum)
				free(tmp);
			return (-1);
		}
		if (!(backup = (char *)malloc(sizeof(char) * (len + len_sum))))
		{
			if (len_sum)
				free(tmp);
			return (-1);
		}
		if (len_sum)
		{
			ft_memcpy(backup, tmp, len_sum);
			free(tmp);
		}
		ft_memcpy(backup + len_sum, buffer, len);
		flag = check_buffer(backup);
		len_sum += len;
		if (flag > 0 || flag == 0)
		{
			len_sum -= flag;
			if ((*line = ft_strdup(backup, flag)) == 0)
			{
				free(backup);
				return (-1);
			}
			if (!flag)
			{
				free(backup);
				return (0);
			}
			if (!(tmp = strdup_buffer(tmp, backup + flag, len_sum)))
				return (-1);
			if (!(backup = strdup_buffer(backup, tmp, len_sum)))
				return (-1); 
			return (1);
		}
		//if (!(tmp = strdup_buffer(tmp, backup, len_sum)))
		//	return (-1);
	}
}

int		read_buffer_first(int fd, char *buffer, char *backup, char **line, ssize_t *len_sum)
{
	char 	*tmp;
	
	if (backup)
		if (!(tmp = strdup_buffer(tmp, backup, len_sum)))
			return (-1);
	if ((len = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	if (!(backup = (char *)malloc(sizeof(char) * len)))
		return (-1);
	ft_memcpy(backup + *len_sum, buffer, len);
	flag = check_buffer(backup);
	len_sum += len;
	if (flag >= 0)
	{
		len_sum -= flag;
		if (!(*line = ft_strdup(backup, flag)))
		{
			free(backup);
			return (-1);
		}
		if (backup[flag] == 4) //when ctrl D : finished
		{
			free(backup);
			return (0);
		}
		if (!(tmp = strdup_buffer(tmp, backup + flag, len_sum)))
			return (-1);
		if (!(backup = strdup_buffer(backup, tmp, len_sum)))
			return (-1);
		return (1);
	}
	//if (!(tmp = strdup_buffer(tmp, backup, len_sum)))
	//	return (-1);
}



int		get_next_line(int fd, char **line)
{
	static char		*backup;
	static ssize_t	len_sum;
	char			*tmp;
	char			buffer[BUFFER_SIZE];

	len_sum = 0;
	if (fd == 0 || line == 0 || BUFFER_SIZE == 0) // 우선예외 처리
		return (-1);
	read_buffer_first(fd, buffer, backup, line, &len_sum);
	read_buffer(fd, buffer, backup, line);
}
