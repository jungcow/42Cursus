/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:18:14 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:27:33 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "bonus/color.h"
#include "bonus/utils.h"
#include "bonus/error.h"

static void	print_error(char *err_str)
{
	write(2, err_str, ft_strlen(err_str));
}

static void	show_error1(int err_num)
{
	if (err_num == -2)
	{
		write(2, ARG_ERR, ft_strlen(ARG_ERR));
		write(1, "\n", 1);
		printf(BLUE);
		printf(USAGE);
		printf(USAGE2);
		printf(CAUSE);
		printf(RESET);
	}
	else if (err_num == -1)
		write(2, MEMORY_ERR, ft_strlen(MEMORY_ERR));
}

static void	show_error2(int err_num)
{
	if (err_num / 10000 == EINVAL)
		print_error(PTHREAD_JOIN_EINVAL_ERR);
	else if (err_num / 10000 == ESRCH)
		print_error(PTHREAD_JOIN_ESRCH_ERR);
	else
		print_error(PTHREAD_JOIN_EDEADLK_ERR);
}

void	show_error(int err_num)
{
	if (err_num < 0)
	{
		show_error1(err_num);
	}
	else if (err_num < 10000)
	{
		if (err_num / 100 == EAGAIN)
			print_error(PTHREAD_CREATE_EAGAIN_ERR);
		else if (err_num / 100 == EPERM)
			print_error(PTHREAD_CREATE_EPERM_ERR);
		else
			print_error(PTHREAD_CREATE_EINVAL_ERR);
	}
	else
	{
		show_error2(err_num);
	}
}
