.PHONY		:	all	re clean fclean

NAME		=	account
CXX			=	clang++
CXXFLAGS	=	-std=c++98 #-Wall -Wextra -Werror

SRCS		=	tests.cpp \
				Account.cpp

OBJS		=	$(SRCS:.cpp=.o)

DEPS		=	$(OBJS:.o=.d)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CXX) $(CXXFLAGS) $^ -o $@

%.o			:	%.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@ -MD

clean		:
			rm -rf $(OBJS) $(DEPS)

fclean		:	clean
			rm -rf $(NAME)

re			:	fclean all

-include $(DEPS)
