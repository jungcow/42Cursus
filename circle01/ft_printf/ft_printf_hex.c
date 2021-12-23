/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:27:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/21 00:03:26 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		alloc_hex_zero(t_format *formats,
								unsigned i, int prec, int width)
{
	char			*str;
	int				len1;
	int				len2;
	int				flag;
	int				capital;

	flag = i < 0 ? 1 : 0;
	i < 0 ? write(1, "-", 1) : 0;
	capital = formats->format == 'X' ? 2 : 1;
	if (!(str = ft_itoa(i, 16, capital)))
		return (0);
	len1 = ft_strlen(str);
	len2 = 0;
	if (prec > len1)
		len2 = prec - len1;
	if (formats->dot == FALSE && formats->flag == '0')
		len2 = width > len1 + flag ? width - (len1 + flag) : 0;
	i = 0;
	while (i++ < (unsigned)len2)
		write(1, "0", 1);
	write(1, str, len1);
	free(str);
	return (len1 + len2 + flag);
}

static int		get_hex_len(t_format *formats, unsigned i, int prec, int width)
{
	char			*str;
	int				len1;
	int				len2;
	int				flag;

	flag = i < 0 ? 1 : 0;
	if (!(str = ft_itoa(i, 16, 1)))
		return (0);
	len1 = ft_strlen(str);
	len2 = 0;
	if (prec > len1)
		len2 = prec - len1;
	if (formats->dot == FALSE && formats->flag == '0')
		len2 = width > len1 + flag ? width - (len1 + flag) : 0;
	free(str);
	return (len1 + len2 + flag);
}

int				ft_printf_hex(t_format *formats, va_list *ap)
{
	unsigned int	i;
	int				j;

	alloc_va_arg(formats, ap, 'd', &i);
	if (i == 0 && formats->precision == 0)
	{
		print_blank(formats->width);
		return (formats->width);
	}
	if (!(j = get_hex_len(formats, i, formats->precision, formats->width)))
		return (-1);
	j = formats->width > j ? formats->width - j : 0;
	if (formats->flag != '-')
		print_blank(j);
	if (!(i = alloc_hex_zero(formats, i, formats->precision, formats->width)))
		return (-1);
	if (formats->flag == '-')
		print_blank(j);
	return (i + j);
}
