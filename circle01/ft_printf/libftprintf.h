/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 01:39:29 by jungwkim          #+#    #+#             */
/*   Updated: 2021/01/27 17:43:26 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define MINUS -1
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_format
{
	char			*tmp;
	int				format;
	int				flag;
	int				width;
	int				width_starred;
	int				dot;
	int				precision;
	int				precision_starred;
	struct s_format	*next;
}					t_format;

size_t				ft_strlen(const char *str);
char				*ft_strndup(char *s1, ssize_t idx);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isformat(int c);
int					ft_isspace(int c);
char				*ft_itoa(unsigned n, unsigned base, int flag);
int					ft_atoi(char **str);
int					ft_printf(const char *str, ...);
void				clear_format(t_format **format, int count);
void				print_blank(int len);
int					init_info(t_format **format);
int					ft_printf_char(t_format *formats, va_list *ap);
int					ft_printf_str(t_format *formats, va_list *ap);
int					ft_printf_int(t_format *formats, va_list *ap);
int					ft_printf_unsigned(t_format *formats, va_list *ap);
int					ft_printf_hex(t_format *formats, va_list *ap);
int					ft_printf_addr(t_format *formats, va_list *ap);
int					ft_printf_per(t_format *formats, va_list *ap);
void				alloc_va_arg(t_format *formats, va_list *ap, int flag, ...);

#endif
