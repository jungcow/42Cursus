/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:40:08 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/27 17:07:13 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_str(t_format *formats, va_list *ap)
{
	char	*tmp;
	int		len1;
	int		len2;
	int		flag;

	alloc_va_arg(formats, ap, 's', &tmp, &flag);
	if (tmp == 0)
		if (!(tmp = ft_strndup("(null)", 6)))
			return (-1);
	len1 = ft_strlen(tmp);
	if (formats->precision < len1 && formats->precision != MINUS)
		len1 = formats->precision;
	len2 = formats->width > len1 ? (formats->width - len1) : 0;
	if (formats->flag != '-')
		print_blank(len2);
	write(1, tmp, len1);
	if (formats->flag == '-')
		print_blank(len2);
	if (flag == 1)
		free(tmp);
	return (len1 + len2);
}
