# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 15:56:39 by jungwkim          #+#    #+#              #
#    Updated: 2021/03/31 12:29:44 by jungwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	:	all clean fclean re bonus
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strslen.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strrchr.c\
			ft_strchr.c\
			ft_strnstr.c\
			ft_strncmp.c\
			ft_strcmp.c\
			ft_atoi.c\
			ft_atof.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_split.c\

BONUS_SRCS	=	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

NAME	=	libft.a

$(NAME)	:	$(OBJS)
			ar rcs $@ $^

OBJS	:	$(SRCS)
			$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

BONUS_OBJS	:	$(BONUS_SRCS)
					$(CC) $(CFLAGS) -c $^ -o $@

bonus	:	$(OBJS) $(BONUS_OBJS)
			ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

all		:	$(NAME)

clean	:
			rm -rf $(OBJS) $(BONUS_OBJS)
	
fclean	: 	clean
			rm -rf $(NAME)

re		:	clean all
