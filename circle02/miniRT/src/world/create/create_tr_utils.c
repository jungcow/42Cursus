/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 03:34:15 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/07 11:00:40 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	scale_triangle(void *obj, int key)
{
	t_triangle	*tri;

	tri = (t_triangle *)obj;
	key = 0;
}

void	apply_rotate_triangle(void (*axis_rotate)(t_vec *orient, double angle),
							t_triangle *tri, double angle)
{
	axis_rotate(&tri->point1, angle);
	axis_rotate(&tri->point2, angle);
	axis_rotate(&tri->point3, angle);
}

void	rotate_triangle(void *obj, int key, double angle)
{
	t_triangle	*tri;
	t_vec		middle;

	tri = (t_triangle *)obj;
	middle = new_vec((tri->point1.x + tri->point2.x + tri->point3.x) / 3,
			(tri->point1.y + tri->point2.y + tri->point3.y) / 3,
			(tri->point1.z + tri->point2.z + tri->point3.z) / 3);
	tri->point1 = sub_vec(tri->point1, middle);
	tri->point2 = sub_vec(tri->point2, middle);
	tri->point3 = sub_vec(tri->point3, middle);
	if (key == KEY_X)
		apply_rotate_triangle(x_axis_rotate, tri, angle);
	if (key == KEY_Y)
		apply_rotate_triangle(y_axis_rotate, tri, angle);
	if (key == KEY_Z)
		apply_rotate_triangle(z_axis_rotate, tri, angle);
	tri->point1 = add_vec(tri->point1, middle);
	tri->point2 = add_vec(tri->point2, middle);
	tri->point3 = add_vec(tri->point3, middle);
}

void	translate_tri_vertex(double *p1, double *p2, double *p3, int num)
{
	*p1 += num;
	*p2 += num;
	*p3 += num;
}

void	translate_triangle(void *obj, int key)
{
	t_triangle	*tri;

	tri = (t_triangle *)obj;
	if (key == ARROW_LEFT)
		translate_tri_vertex(&tri->point1.x,
							&tri->point2.x, &tri->point3.x, -1);
	else if (key == ARROW_RIGHT)
		translate_tri_vertex(&tri->point1.x, &tri->point2.x, &tri->point3.x, 1);
	else if (key == ARROW_DOWN)
		translate_tri_vertex(&tri->point1.z,
							&tri->point2.z, &tri->point3.z, -1);
	else if (key == ARROW_UP)
		translate_tri_vertex(&tri->point1.z, &tri->point2.z, &tri->point3.z, 1);
	else if (key == KEY_B)
		translate_tri_vertex(&tri->point1.y,
							&tri->point2.y, &tri->point3.y, -1);
	else if (key == KEY_F)
		translate_tri_vertex(&tri->point1.y, &tri->point2.y, &tri->point3.y, 1);
}
