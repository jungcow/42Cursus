NAME	=	philo
INC		=	-I ./includes
LIBS	=	-lpthread
CC		=	gcc
#CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

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
					timer_thread_utils.c \
					death_timer_utils.c \
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
