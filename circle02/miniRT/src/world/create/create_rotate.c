/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 02:20:02 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/24 17:23:21 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include <math.h>

void		random_axis_rotate(t_vec *metrix, t_vec dir)
{
	t_vec	u;
	t_vec	v;
	double	n;
	double	m;

	init_metrix(&u, &v, &n, &dir);
	m = sqrt(1 - n * n);
	metrix[0] = new_vec(
			n + pow(v.x, 2.0) * (1 - n),
			v.x * v.y * (1 - n) - v.z * m,
			v.z * v.x * (1 - n) + v.y * m);
	metrix[1] = new_vec(
			v.y * v.x * (1 - n) + v.z * m,
			n + pow(v.y, 2.0) * (1 - n),
			v.y * v.z * (1 - n) - v.x * m);
	metrix[2] = new_vec(
			v.z * v.x * (1 - n) - v.y * m,
			v.z * v.y * (1 - n) + v.x * m,
			n + pow(v.z, 2.0) * (1 - n));
	if (cmp_vec(dir, 0, 0, 1))
	{
		metrix[0] = new_vec(1, 0, 0);
		metrix[1] = new_vec(0, 1, 0);
		metrix[2] = new_vec(0, 0, 1);
	}
}

void		x_axis_rotate(t_vec *orient, double a)
{
	t_vec	metrix[3];

	metrix[0] = new_vec(1, 0, 0);
	metrix[1] = new_vec(0, cos(a), -1 * sin(a));
	metrix[2] = new_vec(0, sin(a), cos(a));
	apply_metrix(metrix, orient);
}

void		y_axis_rotate(t_vec *orient, double a)
{
	t_vec	metrix[3];

	metrix[0] = new_vec(cos(a), 0, sin(a));
	metrix[1] = new_vec(0, 1, 0);
	metrix[2] = new_vec(-1 * sin(a), 0, cos(a));
	apply_metrix(metrix, orient);
}

void		z_axis_rotate(t_vec *orient, double a)
{
	t_vec	metrix[3];

	metrix[0] = new_vec(cos(a), -1 * sin(a), 0);
	metrix[1] = new_vec(sin(a), cos(a), 0);
	metrix[2] = new_vec(0, 0, 1);
	apply_metrix(metrix, orient);
}

void		reverse_rotate_metrix(t_vec *metrix)
{
	metrix[0] = new_vec(metrix[0].x, metrix[1].x, metrix[2].x);
	metrix[1] = new_vec(metrix[0].y, metrix[1].y, metrix[2].y);
	metrix[2] = new_vec(metrix[0].z, metrix[1].z, metrix[2].z);
}
