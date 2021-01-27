/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:13:31 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/27 17:20:03 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_zero(int len)
{
	while (len--)
		write(1, "0", 1);
}

int		ft_printf_per(t_format *formats, va_list *ap)
{
	int		len;

	alloc_va_arg(formats, ap, 0);
	len = formats->width > 1 ? formats->width - 1 : 0;
	if (formats->flag != '-')
	{
		if (formats->flag == '0')
			print_zero(len);
		else
			print_blank(len);
	}
	write(1, "%", 1);
	if (formats->flag == '-')
		print_blank(len);
	return (len + 1);
}
