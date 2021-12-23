/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:37:59 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 19:03:10 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "simulate.h"
#include "utils.h"
#include "validate.h"
#include "error.h"

int	main(int argc, char *argv[])
{
	int	ret;

	if (!validate_arguments(argc, argv))
	{
		show_error(ARG_ERR_NUM);
		return (1);
	}
	ret = simulate(argc, argv);
	if (ret)
		show_error(ret);
	else
		printf("시뮬레이션이 종료되었습니다.\n");
	return (ret);
}
