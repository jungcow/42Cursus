/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:56:34 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/30 21:52:06 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_others(char **strs, char *id)
{
	int		(*f)(char **);

	f = NULL;
	if (!ft_strcmp(id, "R"))
		f = validate_r;
	else if (!ft_strcmp(id, "A"))
		f = validate_a;
	else if (!ft_strcmp(id, "c"))
		f = validate_c;
	else if (!ft_strcmp(id, "l"))
		f = validate_l;
	else if (!ft_strcmp(id, "sp"))
		f = validate_sp;
	else if (!ft_strcmp(id, "pl"))
		f = validate_pl;
	else if (!ft_strcmp(id, "sq"))
		f = validate_sq;
	else if (!ft_strcmp(id, "cy"))
		f = validate_cy;
	else if (!ft_strcmp(id, "tr"))
		f = validate_tr;
	if (!f || !f(strs))
		return (0);
	return (1);
}
