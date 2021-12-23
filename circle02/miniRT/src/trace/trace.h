/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:06:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/09 14:55:35 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "ft_stddef.h"
# include "world/create/create.h"
# include "utils/utils.h"

void		trace(t_world *world, t_mlx *mlx);
int			trace_world(t_world *world, t_ray *ray, t_hit *hit);
void		trace_light(t_world *world, t_hit *hit);
int			make_bmp(t_mlx *mlx);

t_vec		diffuse_light(t_light *light, t_ray *shadow, t_hit *hit);
t_vec		specular_light(t_light *light, t_hit *hit);

#endif
