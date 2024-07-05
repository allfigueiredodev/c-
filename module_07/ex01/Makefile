# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 18:06:59 by aperis-p          #+#    #+#              #
#    Updated: 2024/07/05 08:32:32 by aperis-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter
MAKE = make
CC = c++
FLAGS =  -Wall -Werror -Wextra -std=c++98 -g3
SRC = main.cpp

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