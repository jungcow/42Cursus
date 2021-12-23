/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:49:48 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/27 20:54:57 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	add_vec(t_vec u, t_vec v)
{
	t_vec	new_vec;

	new_vec.x = u.x + v.x;
	new_vec.y = u.y + v.y;
	new_vec.z = u.z + v.z;
	return (new_vec);
}
