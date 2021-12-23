/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 02:49:08 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 09:03:47 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

/*
**	t_vec
*/
# include "ft_stddef.h"

t_vec	new_vec(double x, double y, double z);

t_vec	add_vec(t_vec u, t_vec v);
t_vec	sub_vec(t_vec u, t_vec v);
t_vec	multi_vec(t_vec vec, double a);
t_vec	div_vec(t_vec vec, double a);

t_vec	cross_vec(t_vec u, t_vec v);
double	dot_vec(t_vec u, t_vec v);

t_vec	normalize_vec(t_vec vec);
int		cmp_vec(t_vec vec, double x, double y, double z);

t_vec	vec_multi_vec(t_vec u, t_vec v);

#endif
