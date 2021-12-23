/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:28:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/30 21:53:06 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static int	ft_isidentifier(t_info *info)
{
	char	**strset;
	int		i;

	if (!(strset = ft_split("R A c sp l pl sq cy tr", ' ')))
		return (0);
	while (info)
	{
		i = 0;
		while (strset[i])
		{
			if (!(ft_strcmp(strset[i], info->elem[0])))
			{
				clear_strs(&strset);
				return (1);
			}
			i++;
		}
		info = info->next;
	}
	clear_strs(&strset);
	return (0);
}

static int	check_capital_identifier(t_info *info)
{
	int		r_flag;
	int		a_flag;
	int		c_flag;

	r_flag = 0;
	a_flag = 0;
	c_flag = 0;
	while (info)
	{
		if (!ft_strcmp(info->elem[0], "R"))
			r_flag++;
		if (!ft_strcmp(info->elem[0], "A"))
			a_flag++;
		if (!ft_strcmp(info->elem[0], "c"))
			c_flag++;
		info = info->next;
	}
	if (r_flag != 1 || a_flag != 1 || c_flag < 1)
		return (0);
	return (1);
}

int			validate_identifier(t_info *info)
{
	if (!(ft_isidentifier(info)))
		return (0);
	if (!(check_capital_identifier(info)))
		return (0);
	return (1);
}
