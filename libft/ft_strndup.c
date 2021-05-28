/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:37:04 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 20:37:24 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(char *str, size_t idx)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (idx + 1));
	if (str == 0)
		return (0);
	while (idx--)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
