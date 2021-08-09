# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 23:55:33 by jungwkim          #+#    #+#              #
#    Updated: 2021/08/10 07:30:01 by jungwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
BONUS_NAME	=	philo_bonus
INC		=	-I ./includes
LIBS	=	-lpthread
CC		=	gcc
#CFLAGS	=	-Wall -Wextra -Werror

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

SIMULATE_SRCS_BONUS	=	$(addprefix ./bonus_srcs/simulate/, \
					simulate.c \
					simulate_utils.c \
					init_simulation.c \
					exec_simulation.c \
					clear_simulation.c \
					philo_process.c \
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

BONUS_SRCS	=	./bonus_srcs/main.c \
				./bonus_srcs/error.c \
				$(VALIDATE_SRCS) \
				$(SIMULATE_SRCS_BONUS) \
				$(UTILS_SRCS)

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

bonus	:	$(BONUS_NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(INC) $(LIBS) -o $(NAME)

$(BONUS_NAME)	:	$(BONUS_OBJS)
		$(CC) $(BONUS_OBJS) $(CFLAGS) $(INC) $(LIBS) -o $(BONUS_NAME)

clean	:
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean	:	clean
		rm -rf $(NAME) $(BONUS_NAME)

re		:	fclean all
