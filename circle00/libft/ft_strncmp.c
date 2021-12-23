/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:07:19 by jungwkim          #+#    #+#             */
/*   Updated: 2020/12/28 14:58:07 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (str1 == 0 && str2 == 0)
		return (0);
	if (str1 == 0 || str2 == 0)
		return (str1 == 0 ? str1[0] : -1 * str2[0]);
	i = 0;
	while (str1[i] && str2[i] && i < (n - 1))
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return (str1[i] - str2[i]);
}
