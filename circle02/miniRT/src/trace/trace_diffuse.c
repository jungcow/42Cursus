/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:32:56 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/12 18:02:31 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include <math.h>

t_vec	diffuse_light(t_light *light, t_ray *shadow, t_hit *hit)
{
	double		angle;
	t_vec		ratio;

	angle = dot_vec(normalize_vec(shadow->dir), normalize_vec(hit->normal));
	if (angle < 0)
		angle = 0;
	ratio = multi_vec(div_vec(light->color, 255.0f), angle * light->ratio);
	return (ratio);
}
