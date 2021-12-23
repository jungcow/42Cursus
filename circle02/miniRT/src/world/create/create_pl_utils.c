/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pl_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 03:32:58 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/10 03:51:38 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	scale_plane(void *obj, int key)
{
	t_plane		*plane;

	plane = (t_plane *)obj;
	key = 0;
}

void	rotate_plane(void *obj, int key, double angle)
{
	t_plane		*plane;

	plane = (t_plane *)obj;
	if (key == KEY_X)
		x_axis_rotate(&plane->orient, angle);
	if (key == KEY_Y)
		y_axis_rotate(&plane->orient, angle);
	if (key == KEY_Z)
		z_axis_rotate(&plane->orient, angle);
}

void	translate_plane(void *obj, int key)
{
	t_plane		*plane;

	plane = (t_plane *)obj;
	if (key == ARROW_LEFT)
		plane->point.x -= 1;
	else if (key == ARROW_RIGHT)
		plane->point.x += 1;
	else if (key == ARROW_DOWN)
		plane->point.z -= 1;
	else if (key == ARROW_UP)
		plane->point.z += 1;
	else if (key == KEY_B)
		plane->point.y -= 1;
	else if (key == KEY_F)
		plane->point.y += 1;
}
