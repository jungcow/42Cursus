/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:15:41 by seunghoh          #+#    #+#             */
/*   Updated: 2021/05/15 13:26:05 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "libft.h"
#include "error/error.h"

bool	validate_semicolon(char *dump, int pos)
{
	bool	is_space;
	int		i;

	i = pos - 1;
	is_space = true;
	while (i >= 0)
	{
		if (ft_strchr(";|<>", dump[i]) != NULL)
			break ;
		if (ft_strchr(" \n", dump[i]) == NULL)
			is_space = false;
		i--;
	}
	if (is_space)
	{
		if (dump[pos + 1] == ';' || (pos && dump[pos - 1] == ';'))
			unexpected_token(D_SEMICOLON);
		else
			unexpected_token(SEMICOLON);
	}
	return (!is_space);
}

bool	validate_pipe(char *dump, int pos)
{
	bool	is_space;
	int		i;

	i = pos - 1;
	is_space = true;
	while (i >= 0)
	{
		if (ft_strchr(";|<>", dump[i]) != NULL)
			break ;
		if (ft_strchr(" \n", dump[i]) == NULL)
			is_space = false;
		i--;
	}
	if (is_space)
	{
		if (dump[pos + 1] == '|' || (pos && dump[pos - 1] == '|'))
			unexpected_token(D_PIPE);
		else
			unexpected_token(PIPE);
	}
	return (!is_space);
}

bool	validate_dquote(char *dump, int pos)
{
	int		i;

	i = 1;
	while (pos >= i && dump[pos - i] == '\\')
		i++;
	if (i % 2 == 1)
		return (true);
	return (false);
}
