NAME	=	pipex
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
INC		=	-I ./includes -I./libft -I./srcs/get_next_line
LIB		=	-L./libft -lft

VALIDATE_SRCS	=	$(addprefix ./srcs/validate/, \
					validate.c \
					)

EXECUTE_SRCS	=	$(addprefix ./srcs/execute/, \
					execute.c \
					execute_utils.c \
					pipeline.c \
					redirect.c \
					)

GNL_SRCS		=	$(addprefix ./srcs/get_next_line/, \
					get_next_line.c \
					get_next_line_utils.c \
					)

SRCS	=	srcs/main.c \
			srcs/error.c \
			$(VALIDATE_SRCS) \
			$(EXECUTE_SRCS) \
			$(GNL_SRCS) \

OBJS	=	$(SRCS:.c=.o)

%.o		:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean	:
	make -C ./libft clean
	rm -rf $(OBJS)

fclean	:	clean
	make -C ./libft fclean
	rm -rf $(NAME)

re		:	fclean all
