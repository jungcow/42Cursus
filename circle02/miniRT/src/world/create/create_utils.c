/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 03:29:01 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/07 11:00:55 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "create.h"

void		init_coefficient(t_ray *ray, t_cylinder *cylinder,
							double radius, t_vec *coefficient)
{
	t_vec	co;

	co = sub_vec(ray->origin, cylinder->point);
	coefficient->x = dot_vec(ray->dir, ray->dir)
					- pow(dot_vec(ray->dir, cylinder->orient), 2.0);
	coefficient->y = 2 * (dot_vec(co, ray->dir) - (dot_vec(co, cylinder->orient)
										* dot_vec(ray->dir, cylinder->orient)));
	coefficient->z = dot_vec(co, co) - pow(dot_vec(co, cylinder->orient), 2.0)
									- pow(radius, 2.0);
}

void		translate(t_vec center, t_vec *vertex)
{
	vertex->x += center.x;
	vertex->y += center.y;
	vertex->z += center.z;
}

void		apply_metrix(t_vec *metrix, t_vec *point)
{
	t_vec	new_vec;

	new_vec.x = dot_vec(metrix[0], *point);
	new_vec.y = dot_vec(metrix[1], *point);
	new_vec.z = dot_vec(metrix[2], *point);
	*point = new_vec;
}

void		init_metrix(t_vec *u, t_vec *v, double *n, t_vec *dir)
{
	*u = new_vec(0, 0, 1);
	*v = cross_vec(*u, *dir);
	*n = dot_vec(normalize_vec(*u), normalize_vec(*dir));
	*v = normalize_vec(*v);
}
