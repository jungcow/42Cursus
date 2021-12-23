/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:18:50 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/09 21:32:53 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

void	clear_ambient(t_ambient **ambient)
{
	free(*ambient);
}

int		create_a(t_world *world, char **strs)
{
	world->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (world->ambient == NULL)
		return (0);
	world->ambient->ratio = ft_atof(strs[1]);
	ft_atov(strs[2], &world->ambient->color);
	return (1);
}
