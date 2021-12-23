/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sp_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 03:31:44 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/10 03:50:24 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	scale_sphere(void *obj, int key)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj;
	if (key == KEY_E)
		sphere->diameter += 1;
	else if (key == KEY_R)
		sphere->diameter -= 1;
}

void	rotate_sphere(void *obj, int key, double angle)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj;
	key = 0;
	angle = 0;
}

void	translate_sphere(void *obj, int key)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj;
	if (key == ARROW_LEFT)
		sphere->center.x -= 1;
	else if (key == ARROW_RIGHT)
		sphere->center.x += 1;
	else if (key == ARROW_DOWN)
		sphere->center.z -= 1;
	else if (key == ARROW_UP)
		sphere->center.z += 1;
	else if (key == KEY_B)
		sphere->center.y -= 1;
	else if (key == KEY_F)
		sphere->center.y += 1;
}
