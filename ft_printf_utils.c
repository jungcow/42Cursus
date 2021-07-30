/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 01:31:37 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/21 00:02:05 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		print_blank(int len)
{
	while (len--)
		write(1, " ", 1);
}

static void	alloc_star(t_format *formats, va_list *ap)
{
	if (formats->width_starred == TRUE)
	{
		if ((formats->width = va_arg(*ap, int)) < 0)
		{
			formats->flag = '-';
			formats->width *= -1;
		}
	}
	if (formats->precision_starred == TRUE)
	{
		if ((formats->precision = va_arg(*ap, int)) < 0)
		{
			formats->precision = MINUS;
			formats->dot = FALSE;
		}
	}
}

void		alloc_va_arg(t_format *formats, va_list *ap, int format, ...)
{
	va_list	aq;

	va_start(aq, format);
	alloc_star(formats, ap);
	if (format == 's')
		if (!(*(va_arg(aq, char **)) = va_arg(*ap, char *)))
			*(va_arg(aq, int *)) = 1;
		else
			*(va_arg(aq, int *)) = 0;
	else if (format == 'd' || format == 'c')
		*(va_arg(aq, int *)) = va_arg(*ap, int);
	else if (format == 'p')
		*(va_arg(aq, void **)) = va_arg(*ap, void *);
	va_end(aq);
	return ;
}

void		clear_format(t_format **formats, int count)
{
	t_format	*ptr;

	while ((*formats) && count--)
	{
		ptr = *formats;
		*formats = (*formats)->next;
		free(ptr->tmp);
		ptr->tmp = NULL;
		free(ptr);
		ptr = NULL;
	}
	free(*formats);
	(*formats) = NULL;
}
