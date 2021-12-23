
NAME		=	megaphone
CC			=	clang++
CXXFLAGS	=	-Wall -Wextra -Wall -std=c++98

SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $< -o $@

%.o	:	%.cpp
		$(CC) $(CFLAGS) -c $^

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re		:	fclean all
