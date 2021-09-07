.PHONY		:	all	re clean fclean

NAME		=	account
RESULT		=	./result.txt
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
			@if [ -e $(RESULT) ]; then \
				rm -rf result.txt; \
			fi

re			:	fclean all

compare		:	all
			@ bash compare.sh

-include $(DEPS)
