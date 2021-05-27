/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:56:14 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/08 00:24:00 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	char		*source;

	if (!dst && !src)
		return (0);
	destination = (char *)dst;
	source = (char *)src;
	while (n--)
		*destination++ = *source++;
	return (dst);
}
