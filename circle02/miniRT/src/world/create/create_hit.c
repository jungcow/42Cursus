/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:23:34 by jungwkim          #+#    #+#             */
/*   Updated: 2021/12/23 22:33:26 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include "utils/utils.h"
#include <math.h>

void	loss_of_significance(double *q, double b, double discr)
{
	if (b > 0)
		*q = -1 / 2.0 * (b + sqrt(discr));
	else
		*q = -1 / 2.0 * (b - sqrt(discr));
}

int		solve_quadratic(double a, double b, double c, t_ray *ray)
{
	double	discr;
	double	q;
	double	time0;
	double	time1;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	loss_of_significance(&q, b, discr);
	time1 = q / a;
	time0 = c / q;
	if (time0 > time1)
		swap_double(&time0, &time1);
	if (time0 > 0.0f)
		ray->time = time0;
	else if (time0 <= 0.0f && time1 > 0.0f)
		ray->time = time1;
	if (ray->time <= 0.0f)
	{
		ray->time = 0.0f;
		return (0);
	}
	return (1);
}

int		solve_plane(t_ray *ray, t_vec point, t_vec n)
{
	t_vec	tmp;
	double	denom;
	double	time;

	n = normalize_vec(n);
	denom = dot_vec(ray->dir, n);
	if (denom <= 1.0e-6 && denom >= -1.0e-6)
		return (0);
	tmp = sub_vec(point, ray->origin);
	time = dot_vec(tmp, n) / denom;
	if (time <= 1.0e-6)
	{
		ray->time = 0.0f;
		return (0);
	}
	ray->time = time;
	return (1);
}

int		solve_triangle(t_ray *ray, t_vec a, t_vec b, t_vec c)
{
	t_vec	u;
	t_vec	v;
	t_vec	w;
	double	s;
	double	t;

	u = sub_vec(b, a);
	v = sub_vec(c, a);
	w = sub_vec(add_vec(ray->origin, multi_vec(ray->dir, ray->time)), a);
	if (dot_vec(u, u) * dot_vec(v, v) == dot_vec(u, v) * dot_vec(v, u))
		return (0);
	s = (dot_vec(v, v) * dot_vec(w, u) - dot_vec(v, u) * dot_vec(w, v))
		/ ((dot_vec(u, u) * dot_vec(v, v)) - (dot_vec(u, v) * dot_vec(v, u)));
	t = (dot_vec(u, u) * dot_vec(w, v) - dot_vec(u, v) * dot_vec(w, u))
		/ (dot_vec(u, u) * dot_vec(v, v) - dot_vec(u, v) * dot_vec(v, u));
	if (s >= 0.0f && t >= 0.0f && s + t <= 1)
		return (1);
	return (0);
}

int		solve_cylinder(t_ray *ray, t_cylinder *cylinder,
					double radius, double height)
{
	t_ray		tmp;
	t_vec		coefficient;
	t_vec		hit;
	t_vec		cp;

	init_coefficient(ray, cylinder, radius, &coefficient);
	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, ray))
		return (0);
	hit = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	cp = sub_vec(hit, cylinder->point);
	if (dot_vec(cp, cylinder->orient) <= height
			&& dot_vec(cp, cylinder->orient) >= 0)
		return (1);
	tmp = *ray;
	init_coefficient(ray, cylinder, radius, &coefficient);
	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, ray))
		return (0);
	hit = add_vec(ray->origin, multi_vec(ray->dir, ray->time));
	cp = sub_vec(hit, cylinder->point);
	if (dot_vec(cp, cylinder->orient) > height
			|| dot_vec(cp, cylinder->orient) < 0)
		return (0);
	return (2);
}
