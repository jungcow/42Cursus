/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 01:12:13 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/06 21:04:50 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read가 읽어온 바이트 수가 0일 땐 오류? 아니면 EOF라서 0을 반환해야하나?

int		read_buffer(int fd, char *buffer, t_backup **backup, char **line)
{
	

void	preset_buffer(t_backup **backup)
{
	(*backup)->sentence = NULL;
	(*backup)->sum = 0;
	(*backup)->tmp = 0;
	
	if (!(tmp = (char *)malloc(sizeof(char) * backup->sentence)))
		return (0);
	ft_memcpy(tmp, backup
int		get_next_line(int fd, char **line)
{
	static t_backup *backup;
	char			*buffer[BUFFER_SIZE];
	char			*tmp;
	int				flag;
	ssize_t			len;
	
	if (fd <= 0 || line == 0 || BUFFER_SIZE == 0)
		return (-1);	
	if (!preset_buffer(&backup))
		return (-1);
	tmp = (char *)malloc(sizeof(char) * backup->sentence);
	ft_memcpy(tmp, backup->sentence, backup->sum); 
	
	
	len = read(fd, buffer, BUFFER_SIZE);
	if (len <= 0)
		return (-1);
	//flag = read_buffer(fd, &buffer, backup, line);
	return (flag);
}
