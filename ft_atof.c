/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:04:07 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/04 19:24:56 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		jump_to_point(const char **str)
{
	while (ft_isspace(**str) && **str)
		(*str)++;
	while (**str == '-' || **str == '+')
		(*str)++;
	while (ft_isdigit(**str) && **str)
		(*str)++;
}

double			ft_atof(const char *str)
{
	int		sum_int;
	double	sum;
	double	point;

	sum_int = ft_atoi(str);
	jump_to_point(&str);
	if (!str || *str != '.')
		return ((double)(sum_int));
	str++;
	sum = 0.0;
	point = 0.1;
	while (ft_isdigit(*str) && *str)
	{
		sum = sum + point * (*str - '0');
		point /= 10;
		str++;
	}
	if (sum_int < 0)
		sum = sum * -1 + sum_int;
	else
		sum += sum_int;
	return (sum);
}
