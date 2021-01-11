#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct		s_backup
{
	char			*str;
	ssize_t			sum;
	char			*tmp;
	int				fd;
	char			buffer[BUFFER_SIZE];
	struct s_backup	*next;	
}					t_backup;

char		*ft_strdup(char *str, ssize_t idx)
{
	char *ptr;
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

int			check_buffer(char *str, ssize_t len)
{
	ssize_t		i;

	i = 0;
	while (len--)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void		*ft_memcpy(void *dst, const void *src, ssize_t len)
{
	char	*destination;
	char	*source;
	ssize_t	i;


	if (!dst && !src)
		return (0);
	destination = (char  *)dst;
	source = (char *)src;
	i = 0;
	while (i < len && source)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

void		realloc_buffer(t_backup **backup, ssize_t start_idx, ssize_t len)
{
	char *ptr;

	ptr = ft_strdup((*backup)->str + start_idx, len);
	free((*backup)->str);
	(*backup)->tmp = (char *)malloc(sizeof(char) * len);
	ft_memcpy((*backup)->tmp, ptr, len);
}

void		init_buffer(t_backup **backup)
{
	(*backup)->str = (char *)malloc(0);
	(*backup)->tmp = (char *)malloc(0);
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
	ptr->str = (char *)malloc(0);
	ptr->tmp = (char *)malloc(0);
	ptr->sum = 0;
	ptr->fd = fd;
	ptr->next = *backup;
	*backup = ptr;
	return (ptr);
}

int		get_next_line2(int fd, char **line)
{
	static t_backup		*backup;
	t_backup			*ptr;
	ssize_t				len;
	ssize_t				flag;

	if (!(ptr = find_buffer(fd, &backup)))
		return (-1);
	while ((len = read(fd, ptr->buffer, BUFFER_SIZE)) > 0)
	{
		ptr->str = (char *)malloc(sizeof(char) * (len + backup->sum));
		ft_memcpy(ptr->str, ptr->tmp, ptr->sum);
		free(ptr->tmp);
		ft_memcpy((ptr->str + ptr->sum), ptr->buffer, len);
		ptr->sum += len;
		flag = check_buffer(ptr->str, ptr->sum);
		if (flag > 0)
		{
			*line = ft_strdup(ptr->str, flag);
			realloc_buffer(&(ptr), flag + 1, (ptr->sum - flag) - 1);
			ptr->sum -= flag + 1;
			return (1);
		}
		ptr->tmp = ft_strdup(ptr->str, ptr->sum);
		free(ptr->str);
	}
	*line = ft_strdup(ptr->str, ptr->sum);
	free(ptr->str);
	return (0);
}

int main(void)
{
	int fd;
	char *line;
	char buffer[100];
	int		len;

	fd = open("example.txt", O_CREAT | O_RDONLY, 0777);
	printf("fd : %d\n", fd);
	if (fd == -1)
		return (1);
	//fd = 0;
	while ((len = get_next_line2(fd, &line)) == 1)
	{
		printf("%d : %s\n", len, line);
	}
	printf("%d : %s\n",len, line);
	close(fd);
	return (0);
}
