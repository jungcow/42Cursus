/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:40:05 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/11 20:38:39 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct		s_backup
{
	char			*str;
	char			*tmp;
	char			buffer[BUFFER_SIZE];
	ssize_t			sum;
	int				fd;
	struct s_backup	*next;
}					t_backup;

char		*ft_strdup(char *str, ssize_t idx)
{
	char	*ptr;
	ssize_t	i;

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

void		*ft_memcpy(void *dst, const void *src, ssize_t len)
{
	char 	*destination;
	char 	*source;
	ssize_t i;

	if (!dst && !src)
		return (0);
	destination = (char *)dst;
	source = (char *)src;
	i = -1;
	while (++i < len)
		destination[i] = source[i];
	return (dst);
}

t_backup	*find_buffer(int fd, t_backup **backup)
{
	t_backup *ptr;

	ptr = *backup;
	while (ptr)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	ptr = (t_backup *)malloc(sizeof(t_backup));
	if (ptr == NULL)
		return (NULL);
	ptr->str = NULL;
	ptr->tmp = NULL;
	ptr->sum = 0;
	ptr->fd = fd;
	ptr->next = *backup;
	*backup = ptr;
	return (ptr);
}

int			check_buffer(char *str, ssize_t len)
{
	ssize_t i;

	i = 0;
	while (len--)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			realloc_buffer(t_backup **backup, ssize_t start_idx, ssize_t len)
{
	char *ptr;

	if (!(ptr = ft_strdup((*backup)->str + start_idx, len)))
		return (0);
	free((*backup)->str);
	if (!((*backup)->tmp = (char *)malloc(sizeof(char) * len)))
		return (0);
	ft_memcpy((*backup)->tmp, ptr, len);
	return (1);
}

int			alloc_line(char **line, t_backup **ptr, ssize_t flag)
{
	(*ptr)->sum -= flag + 1;
	if (!(*line = ft_strdup((*ptr)->str, flag)))
		return (0);
	if (!(realloc_buffer(ptr, flag + 1, (*ptr->sum))))
		return (0);
	return (1);
}

int			read_buffer(int fd, t_backup *ptr, char **line)
{
	ssize_t				len;
	ssize_t				flag;

	while ((len = read(fd, ptr->buffer, BUFFER_SIZE)) > 0)
	{
		if (!(ptr->str = (char *)malloc(sizeof(char) * (len + ptr->sum))))
			return (-1);
		ft_memcpy(ptr->str, ptr->tmp, ptr->sum);
		free(ptr->tmp);
		ptr->tmp = NULL;
		ft_memcpy((ptr->str + ptr->sum), ptr->buffer, len);
		ptr->sum += len;
		flag = check_buffer(ptr->str, ptr->sum);
		if (flag >= 0)
		{
			if (!(alloc_line(line, &ptr, flag)))
				return (-1);
			return (1);
		}
		if (!(ptr->tmp = ft_strdup(ptr->str, ptr->sum)))
			return (-1);
		free(ptr->str);
		ptr->str = NULL;
	}
	return (0);
}

int			read_buffer_rest(t_backup *ptr, char **line)
{
	ssize_t	flag;

	while (*(ptr->tmp))
	{
		if (!(ptr->str = (char *)malloc(sizeof(char) * len)))
			return (-1);
		ft_memcpy(ptr->str, ptr->tmp, ptr->sum);
		free(ptr->tmp);
		ptr->tmp = NULL;
		flag = check_buffer(ptr->tmp, ptr->sum);
		if (flag >= 0)
		{
			if (!(alloc_line(line, &ptr, flag)))
				return (-1);
			return (1);
		}
		if (!(ptr->tmp = ft_strdup(ptr->str, ptr->sum)))
			return (-1);
		free(ptr->str);
		ptr->str = NULL;
	}
	return (0);
}


void		clear_buffer(t_backup **backup)
{
	t_backup *ptr;
	t_backup *tmp;

	ptr = *backup;
	while (ptr)
	{
		free(ptr->str);
		free(ptr->tmp);
		ptr->next = tmp;
		free(ptr);
		ptr = tmp;
	}
	*backup = NULL;
}

int			get_next_line(int fd, char **line)
{
	static t_backup		*backup;
	t_backup			*ptr;
	ssize_t				flag;

	if (line == 0 || BUFFER_SIZE == 0)
		return (-1);
	if (!(ptr = find_buffer(fd, &backup)))
		return (-1);
	if ((flag = read_buffer(fd, ptr, line)) == -1)
	{
		clear_buffer(&backup);
		return (-1);
	}
	if (flag == 1)
		return (1);
	if (!(flag))
		read_buffer_rest(ptr, line);
	return (0);
}
int main(void)
{
	int fd;
	int fd2;
	char *line;
	char buffer[100];
	int		len;

	fd = open("example.txt", O_CREAT | O_RDONLY, 0777);
	fd2 = open("example2.txt", O_CREAT | O_RDONLY, 0777);
	printf("fd : %d\n", fd);
	printf("fd2 : %d\n", fd2);
	if (fd == -1)
		return (1);
	//fd = 0;
	//len = read(fd, buffer, 100);
	//printf("%d\n", len);
	/*while ((len = get_next_line(fd, &line)) == 1)
	{
		printf("%d : %s\n", len, line);
	}*/
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	//printf("%d : %s\n",len, line);
	close(fd);
	close(fd2);
	return (0);
}

