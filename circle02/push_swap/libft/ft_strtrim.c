/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:29:42 by jungwkim          #+#    #+#             */
/*   Updated: 2020/12/29 15:39:49 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	long long		j;
	unsigned int	k;
	char			*str;

	i = 0;
	k = 0;
	if (!s1)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[j]) && j-- > 0)
		k++;
	j = ft_strlen(s1) - (k + i);
	if (j <= 0)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == 0)
		return (0);
	k = 0;
	while (j--)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
