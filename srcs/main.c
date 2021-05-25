/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:11:20 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/25 18:06:50 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"
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
	a_to_b(&pair, pair.a.size);
	return (0);
}
