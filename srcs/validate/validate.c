/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:37:54 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/02 17:34:03 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_no_minus_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 19)
			return (0);
		if (ft_strcmp("9223372036854775807", argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	validate_arguments(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (0);
	if (!check_no_minus_digit(argv))
		return (0);
	if (!check_range(argv))
		return (0);
	return (1);
}
