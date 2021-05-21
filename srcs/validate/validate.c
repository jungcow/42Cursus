/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:15:06 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 01:38:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		ft_isinteger(char *arg)
{
	int			minus;
	long long	value;
	char		*tmp;

	minus = 0;
	if (ft_strchr(arg, '-'))
		minus = 1;
	tmp = arg;
	tmp += minus;
	while (*tmp == '0')
		tmp++;
	if ((int)ft_strlen(tmp) > 10 + minus)
		return (0);
	value = ft_atoll(arg);
	if (minus)
	{
		if (value < -2147483648)
			return (0);
	}
	else
	{
		if (value > 2147483647)
			return (0);
	}
	return (1);
}

int		check_integer(int argc, char *arg)
{
	int		i;

	i = 0;
	argc = 0;
	if (ft_strchr(arg + 1, '-') || ft_strchr(arg + 1, '+'))
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
		{
			return (0);
		}
		i++;
	}
	if (!ft_isinteger(arg))
	{
		return (0);
	}
	return (1);
}

int		check_dup(char *arg, char ***buf, int idx)
{
	int		i;
	int		j;

	j = 0;
	while (j < idx + 1)
	{
		i = 0;
		while (buf[j][i])
		{
			if (ft_atoi(buf[j][i]) == ft_atoi(arg))
				return (0);
			i++;
		}
		j++;
	}
	buf[idx][i] = ft_strdup(arg);
	if (buf[idx][i] == NULL)
		exit(-1);
	return (1);
}

int		validate_arg(int argc, char *argv[], char ***buf, int idx)
{
	int		i;

	buf[idx] = (char **)malloc(sizeof(char *) * (argc + 1));
	if (buf[idx] == NULL)
		exit(-1);
	i = 0;
	while (i < argc)
		buf[idx][i++] = NULL;
	buf[idx][i] = NULL;
	i = 0;
	while (argv[i])
	{
		if (!check_integer(argc, argv[i]) || !check_dup(argv[i], buf, idx))
			return (0);
		i++;
	}
	return (1);
}

int		validate_argv(int argc, char *argv[], char ****buf)
{
	int		i;
	char	**strs;

	*buf = (char ***)malloc(sizeof(char **) * (argc));
	if (*buf == NULL)
		exit(-1);
	(*buf)[argc - 1] = NULL;
	i = 0;
	while (++i < argc)
	{
		strs = ft_split(argv[i], ' ');
		if (strs == NULL)
			exit(-1);
		if (!validate_arg(ft_strslen(strs), strs, *buf, i - 1))
		{
			while (argc--)
				ft_strsfree((*buf)[argc]);
			free(*buf);
			ft_strsfree(strs);
			return (0);
		}
		ft_strsfree(strs);
	}
	return (1);
}
