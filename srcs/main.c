/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:59:10 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 14:31:07 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char *argv[])
{
	t_execute	execute;

	if (!validate(argc, argv))
		return (1);
	init_execution(&execute, argc, argv);
	ft_execute(&execute, argv + 2);
	return (0);
}
