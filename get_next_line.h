/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:58:59 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/06 20:20:17 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct		s_backup
{
	char 			*sentence;
	char			buffer[BUFFER_SIZE];
	ssize_t			sum;
	char 			*tmp;
	struct s_backup *next;
}					t_backup;

int		get_next_line(int fd, char **line);

#endif

