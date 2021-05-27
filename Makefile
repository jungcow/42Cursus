NAME	=	pipex
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	./includes
LIB		=	-L./libft -lft

SRCS	=	srcs/main.c

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
