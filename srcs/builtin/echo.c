/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:31 by seunghoh          #+#    #+#             */
/*   Updated: 2021/05/06 22:06:22 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "libft.h"

int		check_option(char *arg)
{
	int		i;
	int		len;

	i = 1;
	len = ft_strlen(arg);
	if (len > 1)
	{
		if (arg[0] != '-')
			return (0);
		while (i < len)
			if (arg[i++] != 'n')
				return (0);
		return (1);
	}
	return (0);
}

int		ft_echo(int argc, char **argv)
{
	int		i;
	bool	new_line;

	i = 1;
	new_line = true;
	if (argc > 1 && check_option(argv[1]))
	{
		new_line = false;
		i++;
	}
	while (i < argc)
	{
		if (write(1, argv[i], ft_strlen(argv[i])) < 0)
			return (errno);
		i++;
		if (i != argc && write(1, " ", 1) < 0)
			return (errno);
	}
	if (new_line)
		write(1, "\n", 1);
	return (errno);
}
