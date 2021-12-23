/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:14:27 by jungwkim          #+#    #+#             */
/*   Updated: 2020/12/30 11:09:26 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && len >= i + 1)
	{
		j = 0;
		tmp = i;
		while (needle[j] == haystack[i] && len >= i + 1
				&& (haystack[i] && needle[j]))
		{
			j++;
			i++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + tmp));
		i = tmp + 1;
	}
	return (0);
}
