NAME	=	push_swap
BONUS_NAME	=	checker
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

OPERATION_SRCS	=	$(addprefix ./srcs/operation/, \
					swap.c \
					push.c \
					rotate.c \
					rev_rotate.c \
					)

SORT_SRCS		=	$(addprefix ./srcs/sort/, \
					sort.c \
					sort_few_nodes.c \
					pivot.c \
					direction.c \
					get_min_max.c \
					)

SRCS	=	./srcs/main.c \
			$(VALIDATE_SRCS) \
			$(CREATE_SRCS) \
			$(OPERATION_SRCS) \
			$(SORT_SRCS) \
			./srcs/test/test_stack.c \
			./srcs/test/test_swap.c \
			./srcs/test/test_push.c \
			./srcs/test/test_push_a.c \
			./srcs/test/test_rotate.c \

BONUS_SRCS		=	$(addprefix ./srcs/checker/, \
					checker.c \
					)					

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		make build_libft
		$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)

bonus	:	$(OBJS) $(BONUS_OBJS)
		$(CC) $(OBJS) $(BONUS_OBJS) $(LIB) $(CFLAGS) -o $(BONUS_NAME)

build_libft	:
		make -C ./libft

clean	:
		make -C ./libft clean
		rm -rf $(OBJS)

fclean	:	clean
		make -C ./libft fclean
		rm -rf $(NAME)

re		:	fclean all
