/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:39:49 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/09 14:59:31 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_stddef.h"

void	header_bmp(char **data, t_mlx *mlx)
{
	unsigned int	size;

	size = mlx->height * mlx->width * 3;
	*(unsigned short *)*data = 0x42;
	*(unsigned short *)(*data + 1) = 0x4D;
	*(unsigned int *)(*data + 2) = size + BMP_HEADER;
	*(unsigned int *)(*data + 6) = 0;
	*(unsigned char *)(*data + 10) = BMP_HEADER;
	*(unsigned int *)(*data + 14) = BMP_HEADER - 14;
	*(unsigned int *)(*data + 18) = mlx->width;
	*(unsigned int *)(*data + 22) = mlx->height;
	*(unsigned short *)(*data + 26) = 1;
	*(unsigned short *)(*data + 28) = 24;
	*(unsigned int *)(*data + 30) = 0;
	*(unsigned int *)(*data + 34) = size;
	*(unsigned int *)(*data + 38) = 3780;
	*(unsigned int *)(*data + 42) = 3780;
	*(int *)(*data + 46) = 0;
	*(int *)(*data + 50) = 0;
}

void	content_bmp(char **data, t_mlx *mlx)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = BMP_HEADER;
	y = mlx->height;
	while (y--)
	{
		x = -1;
		while (++x < mlx->width)
		{
			j = (x * (mlx->bpp / 8)) +
					(y * mlx->line);
			*(*data + i++) = *(mlx->addr + j++);
			*(*data + i++) = *(mlx->addr + j++);
			*(*data + i++) = *(mlx->addr + j);
		}
	}
}

int		make_bmp(t_mlx *mlx)
{
	int				fd;
	unsigned int	size;
	unsigned int	i;
	char			*data;

	size = mlx->height * mlx->width * 3;
	data = malloc(size + BMP_HEADER);
	if (data == NULL)
		return (1);
	i = 0;
	while (i < size + BMP_HEADER)
		data[i++] = 0;
	header_bmp(&data, mlx);
	content_bmp(&data, mlx);
	fd = open("result.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0)
	{
		free(data);
		return (1);
	}
	write(fd, data, size + BMP_HEADER);
	free(data);
	close(fd);
	return (0);
}
