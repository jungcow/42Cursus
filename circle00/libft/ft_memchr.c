/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:29:02 by jungwkim          #+#    #+#             */
/*   Updated: 2020/12/28 12:11:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	unsigned char	ch;

	str = s;
	ch = c;
	while (n--)
	{
		if (*str == c)
			return ((void *)str);
		str++;
	}
	return (0);
}
