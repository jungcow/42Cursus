/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 02:41:27 by jungwkim          #+#    #+#             */
/*   Updated: 2021/07/14 23:14:23 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

int		check_argument(char **argv, int *save)
{
	if (!check_filename(argv[1]))
		return (0);
	if (argv[2])
	{
		if (ft_strcmp(argv[2], "--save"))
		{
			*save = 0;
			return (0);
		}
		*save = 1;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_world		*world;
	t_mlx		mlx;
	t_info		*info;
	int			save;

	info = NULL;
	save = 0;
	if ((argc < 2 || argc > 3)
			|| !check_argument(argv, &save) || !(info = parsing(argv[1])))
	{
		printf("parse error\n");
		clear_info(&info);
		return (0);
	}
	if (!(world = create_world(info)))
		return (0);
	create_mlx(world, &mlx);
	printf("rendering world...\n");
	trace(world, &mlx);
	if (save)
	{
		make_bmp(&mlx);
		exit(0);
	}
	event_listener(&world, &mlx);
	return (0);
}
