/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:32:58 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 14:39:58 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "libft.h"

int		ft_error(char *str)
{
	write(2, "Error: ", ft_strlen("Error: "));
	write(2, str, ft_strlen(str));
	write(1, "\n", 1);
	return (0);
}

int		ft_error_str(char *err_type, char *cause)
{
	write(2, cause, ft_strlen(cause));
	write(2, ": ", 2);
	write(2, err_type, ft_strlen(err_type));
	write(1, "\n", 1);
	return (0);
}
