#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/AForm/AForm.hpp"
#include "Classes/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Classes/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

void TestPresidentialPardonForm(void){
	PresidentialPardonForm pardonForm("Allesson");
	std::cout << YELLOW << pardonForm << DFT << std::endl;
};

void TestShrubberyCreationForm(void){
	ShrubberyCreationForm ShrubForm("Allesson");
	std::cout << YELLOW << ShrubForm << DFT << std::endl;
}

void TestRobotomyRequestForm(void){
	RobotomyRequestForm RobotForm("Allesson");
	std::cout << YELLOW << RobotForm << DFT << std::endl;
}

int main(void) {
	TestPresidentialPardonForm();
	TestShrubberyCreationForm();
	TestRobotomyRequestForm();
}