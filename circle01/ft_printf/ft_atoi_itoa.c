/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:25:33 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/27 17:30:25 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(char **str)
{
	int		sign;
	int		sum;

	sign = 1;
	sum = 0;
	while (ft_isspace(**str) && **str)
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (ft_isdigit(**str) && **str)
	{
		if (sum < 0)
			return ((sign < 0) ? 0 : -1);
		sum = sum * 10 + **str - '0';
		(*str)++;
	}
	return (sum * sign);
}

static void	count_digits(unsigned int n,
		unsigned int *k, unsigned base, int flag)
{
	if (n >= base)
	{
		*k += 1;
		count_digits(n / base, k, base, flag);
	}
	else
		return ;
}

static void	put_num_str(char *str, unsigned int n, unsigned base, int flag)
{
	char	*base_str;

	if (flag == 0)
		base_str = "0123456789";
	else if (flag == 1)
		base_str = "0123456789abcdef";
	else if (flag == 2)
		base_str = "0123456789ABCDEF";
	if (n < base)
	{
		*str = base_str[n % base];
		return ;
	}
	put_num_str(str - 1, n / base, base, flag);
	*str = base_str[n % base];
}

char		*ft_itoa(unsigned int num, unsigned base, int flag)
{
	unsigned int	k;
	char			*str;

	k = 1;
	count_digits(num, &k, base, flag);
	str = (char *)malloc(sizeof(char) * (k + 1));
	if (str == 0)
		return (0);
	put_num_str(str + k - 1, num, base, flag);
	str[k] = '\0';
	return (str);
}
