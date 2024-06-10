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