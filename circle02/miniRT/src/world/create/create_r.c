/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:06:57 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/29 18:52:58 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	clear_resolution(t_resolution **resolution)
{
	free(*resolution);
}

void	init_resolution(t_resolution *r, char **strs)
{
	r->width = ft_atoi(strs[1]);
	if (r->width > 100000 || r->width < 0)
		r->width = 100000;
	r->height = ft_atoi(strs[2]);
	if (r->height > 100000 || r->height < 0)
		r->height = 100000;
	r->a_ratio = r->width / (double)r->height;
}

int		create_r(t_world *world, char **strs)
{
	world->resolution = (t_resolution *)malloc(sizeof(t_resolution));
	if (world->resolution == NULL)
		return (0);
	init_resolution(world->resolution, strs);
	return (1);
}
