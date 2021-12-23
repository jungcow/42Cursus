/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cy_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 03:35:10 by jungwkim          #+#    #+#             */
/*   Updated: 2021/12/23 22:32:41 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	scale_cylinder(void *obj, int key)
{
	t_cylinder		*cy;

	cy = (t_cylinder *)obj;
	if (key == KEY_E)
	{
		cy->height += 1;
		cy->diameter += 1;
	}
	else if (key == KEY_R)
	{
		cy->height -= 1;
		cy->diameter -= 1;
	}
}

void	rotate_cylinder(void *obj, int key, double angle)
{
	t_cylinder		*cy;

	cy = (t_cylinder *)obj;
	if (key == KEY_X)
		x_axis_rotate(&cy->orient, angle);
	if (key == KEY_Y)
		y_axis_rotate(&cy->orient, angle);
	if (key == KEY_Z)
		z_axis_rotate(&cy->orient, angle);
}

void	translate_cylinder(void *obj, int key)
{
	t_cylinder		*cy;

	cy = (t_cylinder *)obj;
	if (key == ARROW_LEFT)
		cy->point.x -= 1;
	else if (key == ARROW_RIGHT)
		cy->point.x += 1;
	else if (key == ARROW_DOWN)
		cy->point.z -= 1;
	else if (key == ARROW_UP)
		cy->point.z += 1;
	else if (key == KEY_B)
		cy->point.y -= 1;
	else if (key == KEY_F)
		cy->point.y += 1;
}

int   solve_quadratic_max(double a, double b, double c, t_ray *ray)
{
  double  discr;
  double  q;
  double  time0;
  double  time1;

  discr = b * b - 4 * a * c;
  if (discr < 0)
    return (0);
  loss_of_significance(&q, b, discr);
  time1 = q / a;
  time0 = c / q;
  if (time0 > time1)
    swap_double(&time0, &time1);
  if (time1 > 0.0f)
    ray->time = time1;
	else
  {
    ray->time = 0.0f;
    return (0);
  }
  return (1);
}
