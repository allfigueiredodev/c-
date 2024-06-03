#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/AForm/AForm.hpp"
#include "Classes/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Classes/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

void TestPresidentialPardonForm(void){
	PresidentialPardonForm pardonForm("Allesson");
	std::cout << MAG_YE << pardonForm << DFT << std::endl;
};

// void TestShrubberyCreationForm(void){

// }

// void TestRobotomyRequestForm(void){

// }

int main(void) {
	TestPresidentialPardonForm();
	// TestShrubberyCreationForm();
	// TestRobotomyRequestForm();
}