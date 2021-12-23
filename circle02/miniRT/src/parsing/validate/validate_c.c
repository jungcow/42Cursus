/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:28:18 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/06 02:49:49 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_c(char **strs)
{
	t_vec	dir;
	double	fov;

	if ((ft_strslen(strs)) != 4)
		return (0);
	if (!ft_iscoordinate(strs[1]))
		return (0);
	if (!ft_atov(strs[2], &dir))
		return (0);
	if (!ft_isrange(dir.x, -1, 1)
			|| !ft_isrange(dir.y, -1, 1)
			|| !ft_isrange(dir.z, -1, 1))
		return (0);
	if (!check_str_to_float(strs[3]))
		return (0);
	fov = ft_atof(strs[3]);
	if (!ft_isrange(fov, 0, 180))
		return (0);
	return (1);
}
