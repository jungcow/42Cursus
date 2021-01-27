/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 02:30:52 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/27 22:41:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flag(t_format *ptr)
{
	int		minus;
	int		zero;

	minus = 0;
	zero = 0;
	while (*(ptr->tmp) == '-' || *(ptr->tmp) == '0')
	{
		if (*(ptr->tmp) == '-')
			minus = 1;
		else if (*(ptr->tmp) == '0')
			zero = 1;
		ptr->tmp++;
	}
	if (minus == 1)
		ptr->flag = '-';
	else if (minus == 0 && zero == 1)
		ptr->flag = '0';
	else
		ptr->flag = FALSE;
}

void	init_width(t_format *ptr)
{
	ptr->width = ft_atoi(&ptr->tmp);
	if (ptr->width < 0)
	{
		ptr->flag = '-';
		ptr->width *= -1;
	}
	if (*(ptr->tmp) == '*')
	{
		ptr->width_starred = TRUE;
		ptr->tmp++;
	}
}

void	init_precision(t_format *ptr)
{
	ptr->tmp++;
	ptr->precision = ft_atoi(&ptr->tmp);
	if (*(ptr->tmp) == '*')
	{
		ptr->precision_starred = TRUE;
		ptr->tmp++;
	}
}

void	init_all(t_format *ptr)
{
	ptr->flag = FALSE;
	ptr->width = 0;
	ptr->width_starred = FALSE;
	ptr->format = 0;
	ptr->dot = FALSE;
	ptr->precision = MINUS;
	ptr->precision_starred = FALSE;
}

int		init_info(t_format **format)
{
	t_format	*ptr;
	char		*tmp;

	tmp = (*format)->tmp;
	ptr = *format;
	init_all(ptr);
	init_flag(ptr);
	init_width(ptr);
	if (*(ptr->tmp) == '.')
	{
		ptr->dot = TRUE;
		init_precision(ptr);
	}
	if (!(ft_isformat(*(ptr->tmp))))
	{
		free(tmp);
		return (0);
	}
	if (!(ptr->next = (t_format *)malloc(sizeof(t_format))))
		return (0);
	ptr->format = *(ptr->tmp);
	ptr->tmp = tmp;
	return (1);
}
