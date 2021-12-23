/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:55:40 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/06 09:02:16 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "libft/libft.h"

/*
**	t_info, t_vec
*/
# include "ft_stddef.h"

/*
**	validate.c
*/
int					validate_others(char **strs, char *id);
int					validate_r(char **strs);
int					validate_a(char **strs);
int					validate_c(char **strs);
int					validate_l(char **strs);
int					validate_sp(char **strs);
int					validate_pl(char **strs);
int					validate_sq(char **strs);
int					validate_cy(char **strs);
int					validate_tr(char **strs);

/*
**	validate_id.c
*/
int					validate_identifier(t_info *info);

/*
**	validate_utils.c
*/
int					ft_isrange(double num, double start, double end);
int					check_str_to_float(char *str);
void				clear_strs(char ***strs);
int					ft_iscoordinate(char *str);
int					ft_atov(char *str, t_vec *vec);

#endif
