#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_backup
{
	char		*str;
	ssize_t		sum;
	char		*tmp;
	char		buffer[BUFFER_SIZE];
}				t_backup;

char	*ft_strdup(char *str, ssize_t idx)
{
	char *ptr;
	ssize_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * idx);
	if (str == 0)
		return (0);
	while (idx--)
	{
		ptr[i] = str[i];
		i++;
	}
	//ptr[i] = '\0';
	return (ptr);
}

int	check_buffer(char *str, ssize_t len)
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

void	*ft_memcpy(void *dst, const void *src, ssize_t len)
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

void	init_backup(t_backup **backup)
{
	(*backup)->str = malloc(0);
	(*backup)->tmp = malloc(0);
}

void	realloc_buffer(t_backup **backup, ssize_t start_idx, ssize_t len)
{
	char *ptr;

	ptr = ft_strdup((*backup)->str + start_idx, len);
	free((*backup)->str);
	(*backup)->tmp = (char *)malloc(sizeof(char) * len);
	ft_memcpy((*backup)->tmp, ptr, len);
}

int		get_next_line2(int fd, char **line)
{
	static t_backup		*backup;
	ssize_t				len;
	ssize_t				flag;

	if (!backup)
		if (!(backup = (t_backup *)malloc(sizeof(t_backup))))
			return (-1);
	while ((len = read(fd, backup->buffer, BUFFER_SIZE)) > 0)
	{
		backup->str = (char *)malloc(sizeof(char) * (len + backup->sum));
		ft_memcpy(backup->str, backup->tmp, backup->sum);
		free(backup->tmp);
		ft_memcpy((backup->str + backup->sum), backup->buffer, len);
		backup->sum += len;
		flag = check_buffer(backup->str, backup->sum);
		if (flag > 0)
		{
			*line = ft_strdup(backup->str, flag);
			*(*line + flag) = (char)NULL;
			realloc_buffer(&(backup), flag + 1, (backup->sum - flag) - 1);
			backup->sum -= flag + 1;
			return (1);
		}
		backup->tmp = ft_strdup(backup->str, backup->sum);
		free(backup->str);
	}
	*line = ft_strdup(backup->str, backup->sum);
	*(*line + backup->sum) = (char)NULL;
	free(backup->str);
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
	while ((len = get_next_line2(fd, &line)) == 1)
	{
		printf("after gnl line: %s\n", line);
	}
	printf("afger gnl line: %s\n", line);
	close(fd);
	return (0);
}
