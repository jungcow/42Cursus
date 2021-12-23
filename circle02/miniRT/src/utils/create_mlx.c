/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:44:19 by jungwkim          #+#    #+#             */
/*   Updated: 2021/12/23 18:20:05 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"

#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080

void	create_mlx(t_world *world, t_mlx *mlx)
{
	mlx->ptr = mlx_init();
//	mlx_get_screen_size(mlx->ptr, &width, &height);
	mlx->width = world->resolution->width;
	mlx->height = world->resolution->height;
	if (mlx->width > MAX_WIDTH)
		mlx->width = MAX_WIDTH;
	if (mlx->height > MAX_HEIGHT)
		mlx->height = MAX_HEIGHT;
	mlx->a_ratio = mlx->width / (double)mlx->height;
	world->resolution->width = mlx->width;
	world->resolution->height = mlx->height;
	world->resolution->a_ratio = mlx->a_ratio;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "minirt");
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img,
								&mlx->bpp, &mlx->line, &mlx->endian);
}
