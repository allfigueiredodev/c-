NAME = polymorphism
MAKE = make
CC = c++
FLAGS =  -Wall -Werror -Wextra -Wshadow -std=c++98 -g3
SRC = main.cpp Animal.class.cpp Cat.class.cpp Dog.class.cpp

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