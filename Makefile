NAME	=	pipex
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
INC		=	-I ./includes -I./libft -I./srcs/get_next_line
LIB		=	-L./libft -lft
PIPE_DIR	=	$(HOME)/Documents/42cursus/subject/circle02/pipex/pipe
FILE_DIR	=	$(HOME)/Documents/42cursus/subject/circle02/pipex/file
FILE1	=	$(HOME)/Documents/42cursus/subject/circle02/pipex/file/file1

VALIDATE_SRCS	=	$(addprefix ./srcs/validate/, \
					validate.c \
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

OBJS	=	$(SRCS:.c=.o)

%.o		:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@if [ ! -d $(PIPE_DIR) ]; then \
		mkdir pipe; \
	fi
	@if [ ! -d $(FILE_DIR) ]; then \
		mkdir file; \
	fi
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus	:	all

clean	:
	make -C ./libft clean
	rm -rf $(OBJS) ./file/file2 ./pipe/*

fclean	:	clean
	make -C ./libft fclean
	rm -rf $(NAME) ./file ./pipe

re		:	fclean all
