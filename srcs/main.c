/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:11:20 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 12:35:47 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

#include "operation.h"
#include <stdio.h>
int		main(int argc, char *argv[])
{
	t_pair	pair;
	char	***buf;

	if (argc < 2 || !validate_argv(argc, argv, &buf))
	{
		write(2, "Error", 5);
		write(1, "\n", 1);
		return (1);
	}
	create_stack(argc, buf, &pair);
	a_to_b(&pair, pair.a.size);
	test_stack(&pair);
	system("leaks push_swap");
	return (0);
}
