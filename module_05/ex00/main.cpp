#include "Bureaucrat.h"

int main(void) {
	Bureaucrat test;
	Bureaucrat test2("qwerty", 148);
	Bureaucrat test3("asdfg", 3);
	std::cout << test << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	test2.decrementGrade();
	std::cout << test2 << std::endl;
	test2.decrementGrade();
	std::cout << test2 << std::endl;
	test2.decrementGrade();
	std::cout << test2 << std::endl;
	test3.incrementGrade();
	std::cout << test3 << std::endl;
	test3.incrementGrade();
	std::cout << test3 << std::endl;
	test3.incrementGrade();
	std::cout << test3 << std::endl;
	test3.incrementGrade();
	std::cout << test3 << std::endl;
}