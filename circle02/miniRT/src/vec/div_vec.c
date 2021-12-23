/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:37:59 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/03 17:39:09 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	div_vec(t_vec vec, double a)
{
	t_vec	new_vec;

	new_vec.x = vec.x / a;
	new_vec.y = vec.y / a;
	new_vec.z = vec.z / a;
	return (new_vec);
}
