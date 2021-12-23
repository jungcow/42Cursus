/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:35:15 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/12 18:43:11 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include <math.h>

t_vec	specular_light(t_light *light, t_hit *hit)
{
	double		angle;
	t_vec		l;
	t_vec		n;
	t_vec		reflect_vec;
	t_vec		ratio;

	l = sub_vec(light->point, hit->point);
	n = hit->normal;
	n = multi_vec(n, 2 * dot_vec(l, n));
	reflect_vec = sub_vec(n, l);
	angle = dot_vec(normalize_vec(reflect_vec),
					normalize_vec(multi_vec(hit->dir, -1)));
	if (angle < 0)
		angle = 0;
	ratio = multi_vec(div_vec(light->color, 255.0f),
							light->ratio * pow(angle, 200.0));
	return (ratio);
}
