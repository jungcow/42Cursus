NAME	=	push_swap
BONUS_NAME	=	checker
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g -fsanitize=address
INC		=	-I ./includes -I ./libft -I ./srcs/get_next_line
LIB		=	-L./libft -lft

GNL_SRCS		=	$(addprefix ./srcs/get_next_line/, \
					get_next_line.c \
					get_next_line_utils.c \
					)

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
					sort_23_nodes.c \
					sort_23_times.c \
					sort_few_times.c \
					pivot.c \
					direction.c \
					get_min_max.c \
					)

SRCS	=	./srcs/main.c \
			$(VALIDATE_SRCS) \
			$(CREATE_SRCS) \
			$(OPERATION_SRCS) \
			$(SORT_SRCS) \
			./srcs/error.c \
			./srcs/sort/test/test_stack.c \

BONUS_SRCS		=	./srcs/checker/checker.c \
					./srcs/checker/check_result.c \
					$(GNL_SRCS) \
					$(VALIDATE_SRCS) \
					$(OPERATION_SRCS) \
					$(CREATE_SRCS) \
					./srcs/error.c \

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

bonus	:	$(BONUS_NAME)

$(NAME)	:	$(OBJS)
		make build_libft
		$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)

$(BONUS_NAME)	:	$(BONUS_OBJS)
		make build_libft
		$(CC) $(BONUS_OBJS) $(LIB) $(CFLAGS) -o $(BONUS_NAME)

build_libft	:
		make -C ./libft

clean	:
		make -C ./libft clean
		rm -rf $(OBJS)
		rm -rf $(BONUS_OBJS)

fclean	:	clean
		make -C ./libft fclean
		rm -rf $(NAME)
		rm -rf $(BONUS_NAME)

re		:	fclean all
