/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:58:59 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 15:33:25 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_backup
{
	char			*str;
	char			*tmp;
	char			buffer[BUFFER_SIZE];
	size_t			sum;
	int				fd;
	struct s_backup	*next;
}					t_backup;

int					get_next_line(int fd, char **line);
t_backup			*find_buffer(int fd, t_backup **backup);
int					read_buffer(int fd, t_backup *ptr, char **line);
int					read_buffer_rest(t_backup *ptr, char **line);
void				clear_buffer(t_backup **backup);
void				del_buffer(int fd, t_backup **backup);
int					check_buffer(char *str, size_t len);
int					realloc_buffer(t_backup *backup, size_t start_idx,
									size_t len);
int					alloc_line(char **line, t_backup *ptr, size_t flag);
char				*ft_strndup(char *str, size_t idx);
void				*ft_memcpy(void	*dst, const void *src, size_t len);

#endif
