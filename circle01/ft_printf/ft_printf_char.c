/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:38:08 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/27 17:11:15 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_char(t_format *formats, va_list *ap)
{
	int		c;
	int		len;

	alloc_va_arg(formats, ap, 'c', &c);
	len = formats->width > 1 ? formats->width - 1 : 0;
	if (formats->flag != '-')
		print_blank(len);
	write(1, &c, 1);
	if (formats->flag == '-')
		print_blank(len);
	return (len + 1);
}
