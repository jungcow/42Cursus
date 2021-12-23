.PHONY		:	all re fclean clean

NAME		=	replace

CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CXX) $(CXXFLAGS) $^ -o $@


%.o			:	%.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean		:
			rm -rf $(OBJS) $(DEPS)

fclean		: clean
			rm -rf $(NAME) *.replace

re			: fclean all
