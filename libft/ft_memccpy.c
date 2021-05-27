/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:41:09 by jungwkim          #+#    #+#             */
/*   Updated: 2020/12/27 18:20:55 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dest;
	const char		*source;

	dest = (char *)dst;
	source = (const char *)src;
	while (n--)
	{
		*dest = *source;
		if ((unsigned char)(*source) == (unsigned char)c)
			return ((void *)(dest + 1));
		dest++;
		source++;
	}
	return (0);
}
