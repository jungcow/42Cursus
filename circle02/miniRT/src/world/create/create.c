/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:01:34 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/11 11:08:27 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int			(*create_object(char *id))(t_world *, char **)
{
	int		(*fp)(t_world *, char **);

	fp = NULL;
	if (!ft_strcmp(id, "pl"))
		fp = create_pl;
	else if (!ft_strcmp(id, "sp"))
		fp = create_sp;
	else if (!ft_strcmp(id, "sq"))
		fp = create_sq;
	else if (!ft_strcmp(id, "cy"))
		fp = create_cy;
	else if (!ft_strcmp(id, "tr"))
		fp = create_tr;
	return (fp);
}

int			create_members(t_world *world, char **strs, char *id)
{
	int		(*fp)(t_world *, char **);

	fp = NULL;
	if (!ft_strcmp(id, "R"))
		fp = create_r;
	else if (!ft_strcmp(id, "A"))
		fp = create_a;
	else if (!ft_strcmp(id, "c"))
		fp = create_c;
	else if (!ft_strcmp(id, "l"))
		fp = create_l;
	else
		fp = create_object(id);
	if (!fp || !fp(world, strs))
		return (0);
	return (1);
}
