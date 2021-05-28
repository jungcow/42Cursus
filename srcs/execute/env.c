/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:31:13 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 21:36:28 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*get_environ(char *env, char *envp[])
{
	char		*ptr;
	char		*key;
	char		*ret;
	int			i;

	i = -1;
	while (envp[++i])
	{
		ptr = ft_strlchr(envp[i], '=');
		key = ft_strndup(envp[i], ptr - envp[i]);
		if (!key)
			exit(-1);
		if (ft_strcmp(key, env) == 0)
		{
			if (ptr + 1 == NULL)
				ret = ft_strdup("");
			else
				ret = ft_strdup(ptr + 1);
			free(key);
			return (ret);
		}
		free(key);
	}
	return (NULL);
}
