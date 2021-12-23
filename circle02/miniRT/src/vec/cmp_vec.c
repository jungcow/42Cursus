/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 03:14:03 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/27 15:15:02 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "../parsing/validate/validate.h"

int		cmp_vec(t_vec vec, double x, double y, double z)
{
	int		flag;

	flag = 0;
	if (ft_isrange(vec.x, x - 1.0e-8, x + 1.0e-8))
		flag++;
	if (ft_isrange(vec.y, y - 1.0e-8, y + 1.0e-8))
		flag++;
	if (ft_isrange(vec.z, z - 1.0e-8, z + 1.0e-8))
		flag++;
	if (flag == 3)
		return (1);
	return (0);
}
