NAME = megaphone
MAKE = make
CC = c++
FLAGS =  -Wall -Werror -Wextra -std=c++98 -g3
SRC = megaphone.cpp

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re