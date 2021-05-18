NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
INC		=	-I ./includes -I ./libft
LIB		=	-L./libft -lft

VALIDATE_SRCS	=	$(addprefix ./srcs/validate/, \
					validate.c \
					)

CREATE_SRCS	=	$(addprefix ./srcs/create/, \
					stack.c \
					)

SRCS	=	./srcs/main.c \
			$(VALIDATE_SRCS) \
			$(CREATE_SRCS) \
			./srcs/test/test_stack.c \

OBJS	=	$(SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		make build_libft
		$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)

build_libft	:
		make -C ./libft

clean	:
		make -C ./libft clean
		rm -rf $(OBJS)

fclean	:	clean
		make -C ./libft fclean
		rm -rf $(NAME)

re		:	fclean all
