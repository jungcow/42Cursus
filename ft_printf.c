/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:21:56 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/28 01:33:15 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		save_info(const char *str, t_format *formats)
{
	char	*tmp;
	int		idx;
	int		jdx;

	tmp = (char *)str;
	idx = 1;
	jdx = -1;
	while (str[idx])
	{
		if (ft_isformat(str[idx]))
		{
			if (!(formats->tmp = (char *)malloc(sizeof(char) * (idx + 2))))
				return (0);
			while (++jdx < idx)
				formats->tmp[jdx] = tmp[jdx + 1];
			formats->tmp[jdx] = '\0';
			return (idx);
		}
		idx++;
	}
	return (0);
}

int		parse_info(const char *str, t_format **formats, int *count)
{
	int			idx;
	int			i;
	t_format	*ptr;

	idx = 0;
	ptr = *formats;
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			if (!(i = save_info(str + idx, ptr)))
				return (0);
			idx += i;
			if (!(init_info(&ptr)))
				return (0);
			*count += 1;
			ptr = ptr->next;
			ptr->next = NULL;
			ptr->tmp = NULL;
		}
		idx++;
	}
	return (1);
}

int		ft_printf_all(t_format *formats, int *sum, va_list *ap)
{
	int		tmp;

	if (formats->format == 'c')
		if ((tmp = ft_printf_char(formats, ap)) == -1)
			return (0);
	if (formats->format == 's')
		if ((tmp = ft_printf_str(formats, ap)) == -1)
			return (0);
	if (formats->format == 'i' || formats->format == 'd')
		if ((tmp = ft_printf_int(formats, ap)) == -1)
			return (0);
	if (formats->format == 'u')
		if ((tmp = ft_printf_unsigned(formats, ap)) == -1)
			return (0);
	if (formats->format == 'p')
		if ((tmp = ft_printf_addr(formats, ap)) == -1)
			return (0);
	if (formats->format == 'x' || formats->format == 'X')
		if ((tmp = ft_printf_hex(formats, ap)) == -1)
			return (0);
	if (formats->format == '%')
		if ((tmp = ft_printf_per(formats, ap)) == -1)
			return (0);
	*sum += tmp;
	return (1);
}

int		ft_printf_loop(const char *str, int *sum,
		t_format *formats, va_list *ap)
{
	int		idx;

	idx = -1;
	while (str[++idx])
	{
		if (str[idx] == '%')
		{
			if (!(ft_printf_all(formats, sum, ap)))
				return (0);
			idx += ft_strlen(formats->tmp);
			if (formats->next)
				formats = formats->next;
			continue;
		}
		*sum += 1;
		write(1, &str[idx], 1);
	}
	return (1);
}

int		ft_printf(const char *str, ...)
{
	t_format	*formats;
	va_list		ap;
	int			sum;
	int			count;

	if (str == 0)
		return (0);
	if (!(formats = (t_format *)malloc(sizeof(t_format))))
		return (0);
	count = 0;
	if (!(parse_info(str, &formats, &count)))
	{
		clear_format(&formats, count);
		return (0);
	}
	sum = 0;
	va_start(ap, str);
	if (!(ft_printf_loop(str, &sum, formats, &ap)))
	{
		clear_format(&formats, count);
		return (0);
	}
	va_end(ap);
	clear_format(&formats, count);
	return (sum);
}
#include <stdio.h>
int main(void)
{
	int i;

	i = 123;
	printf("%d\n", printf("%05c", i));
	return (0);
}
	
