/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:52 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/27 18:58:20 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <math.h>

t_vec	normalize_vec(t_vec vec)
{
	double	l;
	t_vec	new_vec;

	l = dot_vec(vec, vec);
	new_vec.x = vec.x / sqrt(l);
	new_vec.y = vec.y / sqrt(l);
	new_vec.z = vec.z / sqrt(l);
	return (new_vec);
}
