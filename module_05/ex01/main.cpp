#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/Form/Form.hpp"

int main(void) {
	Bureaucrat test2("qwerty", 148);
	Bureaucrat test3("asdfg", 6);
	Form ACP28("ACP28", 4, 2);
	ACP28.beSigned(test3);
	test3.incrementGrade();
	test3.incrementGrade();
	test3.incrementGrade();
	test3.decrementGrade();
	std::cout << CYAN << test3.getGrade() << DFT << std::endl;
	ACP28.beSigned(test3);
	ACP28.beSigned(test3);
	test3.signForm(ACP28);
}