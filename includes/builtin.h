/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:35:17 by seunghoh          #+#    #+#             */
/*   Updated: 2021/05/07 19:54:40 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "environ/environ.h"

int		ft_echo(int argc, char **argv, t_environ *environ);
int		ft_pwd(void);
int		ft_cd(int argc, char **argv, t_environ *environ);
int		ft_export(int argc, char **argv, t_environ *environ);
int		ft_unset(int argc, char **argv, t_environ *environ);
int		ft_env(int argc, char **argv, t_environ *environ);
int		ft_exit(int argc, char **argv, t_environ *environ);

#endif
