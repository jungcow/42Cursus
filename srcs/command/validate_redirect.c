/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:04:16 by seunghoh          #+#    #+#             */
/*   Updated: 2021/05/02 18:02:38 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "libft.h"
#include "error/error.h"

bool	validate_input_redirect(char *dump, int pos)
{
	bool	is_space;
	int		i;

	i = pos;
	is_space = false;
	while (--i >= 0)
	{
		if (ft_strchr("<>", dump[i]) != NULL)
		{
			is_space = true;
			break ;
		}
		else if (ft_strchr(" \n", dump[i]) == NULL)
			break ;
	}
	if (is_space)
	{
		if (dump[pos + 1] == '<' && dump[pos + 2] == '<')
			unexpected_token(T_IN_REDIRECT);
		else if (dump[pos + 1] == '<')
			unexpected_token(D_IN_REDIRECT);
		else
			unexpected_token(IN_REDIRECT);
	}
	return (!is_space);
}

bool	validate_output_redirect(char *dump, int pos)
{
	bool	is_space;
	int		i;

	i = pos - 1;
	is_space = false;
	while (i >= 0)
	{
		if (ft_strchr("<>", dump[i]) != NULL)
		{
			is_space = true;
			break;
		}
		else if (ft_strchr(" \n", dump[i]) == NULL)
			break ;
		i--;
	}
	if (is_space)
	{
		if (dump[pos + 1] == '>')
			unexpected_token(D_OUT_REDIRECT);
		else
			unexpected_token(OUT_REDIRECT);
	}
	return (!is_space);
}

bool	validate_redirect(char *dump, int i)
{
	if (dump[i] == '<')
		return (validate_input_redirect(dump, i));
	else
		return (validate_output_redirect(dump, i));
}
