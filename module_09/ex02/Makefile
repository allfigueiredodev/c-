# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 21:45:53 by aperis-p          #+#    #+#              #
#    Updated: 2024/07/19 21:45:56 by aperis-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
MAKE = make
CC = c++
FLAGS =  -Wall -Werror -Wextra -std=c++98 -g3
SRC = main.cpp Classes/PmergeMe/PmergeMe.cpp

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