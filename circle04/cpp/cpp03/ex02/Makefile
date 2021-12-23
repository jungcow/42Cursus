.PHONY		:	all re clean fclean

NAME			=	fragTrap
CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS			=	./main.cpp \
					./ClapTrap.cpp \
					./ScavTrap.cpp \
					./FragTrap.cpp 

OBJS			=	$(SRCS:.cpp=.o)
DEPS			=	$(OBJS:.o=.d)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CXX) $(CXXFLAGS) $^ -o $@

%.o				:	%.cpp
				$(CXX) $(CXXFLAGS) -c $< -o $@ -MD

clean			:
				rm -rf $(OBJS) $(DEPS)

fclean			: clean
				rm -rf $(NAME)

re				: fclean all

-include $(DEPS)
