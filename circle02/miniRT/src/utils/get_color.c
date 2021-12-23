/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:33:45 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/03 16:33:38 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double		get_color(t_vec color)
{
	int			r;
	int			g;
	int			b;

	r = (int)color.x << 16;
	g = (int)color.y << 8;
	b = (int)color.z;
	return ((double)(r | g | b) / (1 << 24));
}
