/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:44:16 by jungwkim          #+#    #+#             */
/*   Updated: 2020/12/28 14:54:34 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	index;
	size_t	srclen;

	if (src == 0)
		return (0);
	srclen = ft_strlen(src);
	index = 0;
	if (dstsize == 0)
		return (srclen);
	while (index + 1 < dstsize && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (srclen);
}
