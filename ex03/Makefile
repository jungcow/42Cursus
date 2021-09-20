.PHONY		:	all re fclean clean	

NAME		=	Intern
CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp

OBJS		=	$(SRCS:.cpp=.o)

DEPS		=	$(OBJS:.o=.d)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CXX) $(CXXFLAGS) $^ -o $@

%.o			:	%.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@ -MD

clean		:
			rm -rf $(OBJS) $(DEPS) *_shrubbery

fclean		:	clean
			rm -rf $(NAME)

re			:	fclean all

-include $(DEPS)
