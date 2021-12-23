/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 04:30:45 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 01:36:57 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "create.h"
#include "validate.h"
#include "error.h"

int		main(int argc, char *argv[])
{
	t_pair	pair;
	char	***buf;

	if (!validate_argv(argc, argv, &buf))
	{
		ft_put_error();
		return (1);
	}
	create_stack(argc, buf, &pair);
	if (!check_result(&pair))
	{
		ft_put_error();
		return (1);
	}
	return (0);
}
