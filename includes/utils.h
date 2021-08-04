/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:34:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 15:55:39 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

int			ft_atoi(const char *str);
long long	ft_atoll(char *str);
char		*ft_itoa(int num);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);

#endif
