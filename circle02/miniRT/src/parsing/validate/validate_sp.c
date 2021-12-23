/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:35:24 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/31 12:34:22 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_sp(char **strs)
{
	t_vec	rgb;

	if ((ft_strslen(strs)) != 4)
		return (0);
	if (!ft_iscoordinate(strs[1]))
		return (0);
	if (!check_str_to_float(strs[2]))
		return (0);
	if (!ft_atov(strs[3], &rgb))
		return (0);
	if (!ft_isrange(rgb.x, 0, 255)
			|| !ft_isrange(rgb.y, 0, 255)
			|| !ft_isrange(rgb.z, 0, 255))
		return (0);
	return (1);
}
