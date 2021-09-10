.PHONY			:	all re clean fclean
NAME			=	zombie
CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS			=	./main.cpp \
					./Zombie.cpp \
					./newZombie.cpp \
					./randomChump.cpp 

OBJS			=	$(SRCS:.cpp=.o)

DEPS			=	$(OBJS:.o=.d)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(CXX) $(CXXFLAGS) $^ -o $(NAME)

%.o				:	%.cpp
					$(CXX) $(CXXFLAGS) -c $< -o $@ -MD

clean			:
				rm -rf $(OBJS) $(DEPS)

fclean			:	clean
				rm -rf $(NAME)

re				: fclean all

-include $(DEPS)
