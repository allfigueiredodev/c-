# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 23:27:21 by aperis-p          #+#    #+#              #
#    Updated: 2024/06/14 23:27:22 by aperis-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
MAKE = make
CC = c++
FLAGS =  -Wall -Werror -Wextra -Wshadow -std=c++98 -g3
SRC = main.cpp Classes/Bureaucrat/Bureaucrat.cpp Classes/AForm/AForm.cpp Classes/PresidentialPardonForm/PresidentialPardonForm.cpp \
Classes/RobotomyRequestForm/RobotomyRequestForm.cpp Classes/ShrubberyCreationForm/ShrubberyCreationForm.cpp \
Classes/Intern/Intern.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o) -I ./

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re