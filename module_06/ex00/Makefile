# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 13:42:34 by aperis-p          #+#    #+#              #
#    Updated: 2024/07/04 13:42:37 by aperis-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
MAKE = make
CC = c++
FLAGS =  -Wall -Werror -Wextra -std=c++98 -g3
SRC = main.cpp Classes/ScalarConverter/ScalarConverter.cpp 

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