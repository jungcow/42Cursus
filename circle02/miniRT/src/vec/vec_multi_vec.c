/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multi_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:54:52 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/03 17:59:18 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_multi_vec(t_vec u, t_vec v)
{
	t_vec	new_vec;

	new_vec.x = u.x * v.x;
	new_vec.y = u.y * v.y;
	new_vec.z = u.z * v.z;
	return (new_vec);
}
