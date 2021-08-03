/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:37:59 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/03 23:45:13 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "validate.h"
#include "simulate.h"

int	main(int argc, char *argv[])
{
	int	ret;

	if (!validate_arguments(argc, argv))
	{
		printf("Invalid Arguments");
		return (1);
	}
	ret = simulate(argc, argv);
	if (ret > 0)
		printf("pthread_craete Error\n");
	else if (ret < 0)
		printf("Memory Error\n");
	return (ret);
}
