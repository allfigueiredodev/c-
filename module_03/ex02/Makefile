NAME = repetitive
MAKE = make
CC = c++
FLAGS =  -Wall -Werror -Wextra -Wshadow -std=c++98 -g3
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

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

run: all
	@clear
	@valgrind --show-leak-kinds=all --leak-check=full -q ./$(NAME)
	@rm -rf $(OBJS)
	@rm -f $(NAME)

.PHONY: all clean fclean re