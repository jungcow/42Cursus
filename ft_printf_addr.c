/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:42:48 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/27 15:53:04 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	count_addr(unsigned long long addr, int *count)
{
	if (addr >= 16)
	{
		count_addr(addr / 16, count);
		*count += 1;
	}
	else
		*count += 1;
}

void	print_addr(t_format *formats, unsigned long long addr, int len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr == 0)
		if (formats->precision == 0)
			write(1, "0x", 2);
		else
			write(1, "0x0", 3);
	else
	{
		if (addr >= 16)
		{
			print_addr(formats, addr / 16, len - 1);
			write(1, &hex[addr % 16], 1);
		}
		else
		{
			write(1, "0x", 2);
			write(1, &hex[addr % 16], 1);
		}
	}
}

int		ft_printf_addr(t_format *formats, va_list *ap)
{
	void				*ptr;
	unsigned long long	addr;
	int					len1;
	int					len2;

	alloc_va_arg(formats, ap, 'p', &ptr);
	addr = (unsigned long long)ptr;
	len1 = 2;
	count_addr(addr, &len1);
	if (addr == 0)
		len1 = formats->precision == 0 ? 2 : 3;
	len2 = 0;
	if (formats->width > len1)
		len2 = formats->width - len1;
	if (formats->flag != '-')
		print_blank(len2);
	print_addr(formats, addr, 12);
	if (formats->flag == '-')
		print_blank(len2);
	return (len1 + len2);
}
