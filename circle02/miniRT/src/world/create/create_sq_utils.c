/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sq_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 03:33:38 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/24 17:32:53 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	scale_square(void *obj, int key)
{
	t_square	*square;

	square = (t_square *)obj;
	if (key == KEY_E)
		square->size += 1;
	else if (key == KEY_R)
		square->size -= 1;
}

void	rotate_square(void *obj, int key, double angle)
{
	t_square	*square;

	square = (t_square *)obj;
	if (key == KEY_X)
		x_axis_rotate(&square->orient, angle);
	if (key == KEY_Y)
		y_axis_rotate(&square->orient, angle);
	if (key == KEY_Z)
		z_axis_rotate(&square->orient, angle);
}

void	translate_square(void *obj, int key)
{
	t_square	*square;

	square = (t_square *)obj;
	if (key == ARROW_LEFT)
		square->point.x -= 1;
	else if (key == ARROW_RIGHT)
		square->point.x += 1;
	else if (key == ARROW_DOWN)
		square->point.z -= 1;
	else if (key == ARROW_UP)
		square->point.z += 1;
	else if (key == KEY_B)
		square->point.y -= 1;
	else if (key == KEY_F)
		square->point.y += 1;
}
