NAME = minishell
CC = gcc
CURSES = -lncurses
INC = -I ./includes -I ./libft
CFLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft $(CURSES)

##########################################################
# Builtin Part                                           #
##########################################################
ECHO = ./srcs/builtin/echo
ECHO_SRCS = $(addprefix ./srcs/builtin/srcs/echo/, \
				echo.c \
			)
ECHO_OBJS = $(ECHO_SRCS:.c=.o)


##########################################################
# Command Part                                           #
##########################################################
COMMAND_SRCS = $(addprefix ./srcs/command/, \
				command.c \
				command_utils.c \
				cursor.c \
				cursor_utils.c \
				general.c \
				end.c \
				history.c \
				term_utils.c \
				validate.c \
				split.c \
				)


##########################################################
# PipeLine Part                                          #
##########################################################

PIPELINE_SRCS = $(addprefix ./srcs/pipeline/, \
				pipeline.c \
				operation.c \
				parse/parse.c \
				)

##########################################################
# General Rule                                           #
##########################################################

SRCS = ./srcs/minishell.c \
		$(COMMAND_SRCS) \
		$(PIPELINE_SRCS)

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(ECHO)
	make build_libft
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)


$(ECHO) : $(ECHO_OBJS)
	make build_libft
	$(CC) $(ECHO_OBJS) $(LIB) $(CFLAGS) -o $(ECHO)

build_libft : 
	make -C ./libft

clean :
	make -C ./libft clean
	rm -rf $(ECHO_OBJS)
	rm -rf $(OBJS)

fclean : clean
	make -C ./libft fclean
	rm -rf $(ECHO)
	rm -rf $(NAME)

re : fclean all
