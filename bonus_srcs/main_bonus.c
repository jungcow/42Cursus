/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:59:10 by jungwkim          #+#    #+#             */
/*   Updated: 2021/06/03 12:26:26 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char *argv[], char *envp[])
{
	t_execute	execute;

	if (!validate(argc, argv))
		return (1);
	init_execution(&execute, argc, argv);
	ft_execute(&execute, envp);
	clear_execution(&execute);
	return (0);
}
