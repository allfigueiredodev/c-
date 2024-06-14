#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/Form/Form.hpp"

void beSignedFormTest(void){
	Form ffix("FFIX", 10, 5);
	Bureaucrat zidane("Zidane", 1);
	ffix.beSigned(zidane);
	ffix.beSigned(zidane);
}

void signFormTest(void){
	Form ffix("FFIX", 10, 5);
	Bureaucrat zidane("Zidane", 1);
	zidane.signForm(ffix);
	zidane.signForm(ffix);
}

void instantiateOverLimitTest(void){
	try {
		Bureaucrat zidane("Zidane", 188);
		std::cout << MAGENTA << "GRADE: " << zidane.getGrade() << DFT << std::endl;
	}
	catch (const Bureaucrat::AtConstructionGradeTooHighException& e){
		std::cout << RED << e.what() << DFT << std::endl;
	}
	catch (const Bureaucrat::AtConstructionGradeTooLowException& e){
		std::cout << RED << e.what() << DFT << std::endl;
	}
}

int main(void) {
	beSignedFormTest();
	signFormTest();
	instantiateOverLimitTest();
}