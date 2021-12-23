/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 01:14:15 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/31 12:34:02 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_l(char **strs)
{
	t_vec	rgb;
	double	ratio;

	if ((ft_strslen(strs)) != 4)
		return (0);
	if (!ft_iscoordinate(strs[1]))
		return (0);
	if (!check_str_to_float(strs[2]))
		return (0);
	ratio = ft_atof(strs[2]);
	if (!ft_isrange(ratio, 0.0, 1.0))
		return (0);
	if (!ft_atov(strs[3], &rgb))
		return (0);
	if (!ft_isrange(rgb.x, 0, 255)
			|| !ft_isrange(rgb.y, 0, 255)
			|| !ft_isrange(rgb.z, 0, 255))
		return (0);
	return (1);
}
