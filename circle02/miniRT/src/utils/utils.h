/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:41:17 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/06 21:16:50 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_stddef.h"

void			swap_double(double *a, double *b);
void			create_mlx(t_world *world, t_mlx *mlx);
double			deg_to_rad(double angle);
double			ft_min(double a, double b);
double			get_color(t_vec color);
void			print_vec(t_vec vec, char *str);

#endif
