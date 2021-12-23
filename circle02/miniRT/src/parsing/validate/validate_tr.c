/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:52:16 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/31 12:35:58 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_tr(char **strs)
{
	t_vec	rgb;

	if ((ft_strslen(strs)) != 5)
		return (0);
	if (!ft_iscoordinate(strs[1]))
		return (0);
	if (!ft_iscoordinate(strs[2]))
		return (0);
	if (!ft_iscoordinate(strs[3]))
		return (0);
	if (!ft_atov(strs[4], &rgb))
		return (0);
	if (!ft_isrange(rgb.x, 0, 255)
			|| !ft_isrange(rgb.y, 0, 255)
			|| !ft_isrange(rgb.z, 0, 255))
		return (0);
	return (1);
}
