.PHONY		:	all re clean fclean
NAME		=	polymorphism02
CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				Brain.cpp

OBJS		=	$(SRCS:.cpp=.o)

DEPS		=	$(OBJS:.o=.d)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CXX) $(CXXFLAGS) $^ -o $@

%.o			:	%.cpp
			$(CXX) $(CXXFLALGS) -c $< -o $@ -MD

clean		:
			rm -rf $(OBJS) $(DEPS)

fclean		:	clean
			rm -rf $(NAME)

re			: fclean all

-include $(DEPS)

