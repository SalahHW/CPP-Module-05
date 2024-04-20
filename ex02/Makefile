# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 12:47:01 by sbouheni          #+#    #+#              #
#    Updated: 2024/04/20 09:39:17 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	bureaucrat

CXX						=	c++
CXXFLAGS				=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS					=	source/main.cpp													\
							class/Bureaucrat/Bureaucrat.cpp									\
							class/AForm/AForm.cpp											\
							class/ShrubberyCreationForm/ShrubberyCreationForm.cpp			\
							class/RobotomyRequestForm/RobotomyRequestForm.cpp				\
							class/PresidentialPardonForm/PresidentialPardonForm.cpp			\
							

OBJS					=	$(SRCS:.cpp=.o)

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean					:
							rm -rf $(OBJS)

fclean					:	clean
							rm -rf $(NAME)

re						:	fclean all

.PHONY					:	all clean fclean re