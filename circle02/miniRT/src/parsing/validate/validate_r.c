/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:15:40 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/31 12:32:47 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_r(char **strs)
{
	int		i;
	int		j;

	if ((ft_strslen(strs)) != 3)
		return (0);
	i = 1;
	while (strs[i])
	{
		j = -1;
		while (strs[i][++j])
			if (!ft_isdigit(strs[i][j]))
				return (0);
		i++;
	}
	return (1);
}
