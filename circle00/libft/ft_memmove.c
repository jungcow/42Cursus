/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:43:23 by jungwkim          #+#    #+#             */
/*   Updated: 2020/12/28 00:49:04 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	dest = (char *)dst;
	source = (const char *)src;
	if (src == dst)
		return (dst);
	else if (src < dst)
	{
		source += len - 1;
		dest += len - 1;
		while (len--)
			*dest-- = *source--;
	}
	else
		while (len--)
			*dest++ = *source++;
	return (dst);
}
