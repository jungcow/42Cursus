/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:08:11 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/31 12:33:11 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_a(char **strs)
{
	double	ratio;
	t_vec	rgb;

	if ((ft_strslen(strs)) != 3)
		return (0);
	if (!check_str_to_float(strs[1]))
		return (0);
	ratio = ft_atof(strs[1]);
	if (!ft_isrange(ratio, 0.0, 1.0))
		return (0);
	if (!ft_atov(strs[2], &rgb))
		return (0);
	if (!ft_isrange(rgb.x, 0, 255)
			|| !ft_isrange(rgb.y, 0, 255)
			|| !ft_isrange(rgb.z, 0, 255))
		return (0);
	return (1);
}
