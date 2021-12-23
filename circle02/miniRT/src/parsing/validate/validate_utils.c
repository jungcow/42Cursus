/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:23:04 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/23 16:07:04 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		ft_isrange(double num, double start, double end)
{
	if (num >= start - 1.0e-6 && num <= end + 1.0e-6)
		return (1);
	return (0);
}

int		check_str_to_float(char *str)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	if (*str == '-')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
			flag++;
		i++;
	}
	if (flag > 1)
		return (0);
	return (1);
}

void	clear_strs(char ***strs)
{
	int		i;

	i = 0;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
}

int		ft_iscoordinate(char *str)
{
	char	**split;
	int		i;
	int		flag;

	if (!(split = ft_split(str, ',')))
		return (0);
	i = 0;
	flag = 0;
	while (split[i])
		i++;
	if (i != 3)
		flag++;
	i = 0;
	while (split[i])
	{
		if (!check_str_to_float(split[i]))
			flag++;
		i++;
	}
	clear_strs(&split);
	if (flag != 0)
		return (0);
	return (1);
}

int		ft_atov(char *str, t_vec *vec)
{
	char	**split;

	if (!ft_iscoordinate(str))
		return (0);
	if (!(split = ft_split(str, ',')))
		return (0);
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	clear_strs(&split);
	return (1);
}
