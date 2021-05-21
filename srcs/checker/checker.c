/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 04:30:45 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 12:38:37 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	crete_stack(argc, buf, &pair);
	read_operation(
