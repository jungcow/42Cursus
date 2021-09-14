.PHONY		:	all re clean fclean

NAME			=	diamondTrap
CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -Wno-shadow
INC				=	-I./includes

SRCS			=	$(addprefix ./srcs/, \
					main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp \
					DiamondTrap.cpp \
					)

OBJS			=	$(SRCS:.cpp=.o)
DEPS			=	$(OBJS:.o=.d)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

%.o				:	%.cpp
				$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ -MD

clean			:
				rm -rf $(OBJS) $(DEPS)

fclean			: clean
				rm -rf $(NAME)

re				: fclean all

-include $(DEPS)
