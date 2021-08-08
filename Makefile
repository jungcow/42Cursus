# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 23:55:33 by jungwkim          #+#    #+#              #
#    Updated: 2021/08/08 23:43:35 by jungwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
INC		=	-I ./includes
LIBS	=	-lpthread
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3

VALIDATE_SRCS	=	$(addprefix ./srcs/validate/, \
					validate.c \
					)

SIMULATE_SRCS	=	$(addprefix ./srcs/simulate/, \
					simulate.c \
					simulate_utils.c \
					init_simulation.c \
					exec_simulation.c \
					clear_simulation.c \
					philo_thread.c \
					timer_thread.c \
					)

UTILS_SRCS		=	$(addprefix ./srcs/utils/, \
					ft_atoi.c \
					ft_atoll.c \
					ft_isdigit.c \
					ft_isspace.c \
					ft_strcmp.c \
					ft_strlen.c \
					)

SRCS	=	./srcs/main.c \
			./srcs/error.c \
			$(VALIDATE_SRCS) \
			$(SIMULATE_SRCS) \
			$(UTILS_SRCS)

OBJS	=	$(SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(INC) $(LIBS) -o $(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re		:	fclean all
