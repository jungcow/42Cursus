ifndef	MAKECMDGOALS
	MAKECMDGOALS = all
endif

NAME	=	pipex

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	-I ./includes -I./libft
LIB		=	-L./libft -lft

PIPE_DIR	=	$(PWD)/.pipe

VALIDATE_SRCS	=	$(addprefix ./srcs/validate/, \
					validate.c \
					)

BONUS_VALIDATE_SRCS = $(addprefix ./srcs/validate/, \
					validate_bonus.c \
					)


EXECUTE_SRCS	=	$(addprefix ./srcs/execute/, \
					execute.c \
					execute_utils.c \
					pipeline.c \
					redirect.c \
					command_path.c \
					command_path_utils.c \
					env.c \
					)

SRCS	=	srcs/main.c \
			srcs/error.c \
			$(VALIDATE_SRCS) \
			$(EXECUTE_SRCS) \

BONUS_SRCS	=	srcs/main.c \
				srcs/error.c \
				$(BONUS_VALIDATE_SRCS) \
				$(EXECUTE_SRCS) \

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

%.o		:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

bonus	: $(BONUS_OBJS) $(NAME)

$(NAME)	:	$(OBJS)
	@if [ ! -d $(PIPE_DIR) ]; then \
		mkdir .pipe; \
	fi
	make -C ./libft
ifeq	($(MAKECMDGOALS),all)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
else ifeq	($(MAKECMDGOALS),$(NAME))
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
else ifeq	($(MAKECMDGOALS),bonus)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIB) -o $(NAME)
endif

clean	:
	make -C ./libft clean
	rm -rf $(OBJS) $(BONUS_OBJS) ./.pipe/*

fclean	:	clean
	make -C ./libft fclean
	rm -rf $(NAME) ./.pipe

re		:	fclean all

.PHONY	:	all re clean fclean bonus
