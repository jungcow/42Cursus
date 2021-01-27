# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 15:56:39 by jungwkim          #+#    #+#              #
#    Updated: 2021/01/27 17:33:23 by jungwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	:	all clean fclean re bonus
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	ft_atoi_itoa.c\
			ft_libft.c\
			ft_printf.c\
			ft_printf_addr.c\
			ft_printf_char.c\
			ft_printf_hex.c\
			ft_printf_init.c\
			ft_printf_int.c\
			ft_printf_per.c\
			ft_printf_str.c\
			ft_printf_unsigned.c\
			ft_printf_utils.c\

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

$(NAME)	:	$(OBJS)
			ar rcs $@ $^

OBJS	:	$(SRCS)
			$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

all		:	$(NAME)

clean	:
			rm -rf $(OBJS) $(BONUS_OBJS)
	
fclean	: 	clean
			rm -rf $(NAME)

re		:	clean all
