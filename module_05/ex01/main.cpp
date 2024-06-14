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

void bureaucratUnderGradeTest(){
	Form ffix("FFIX", 10, 5);
	Bureaucrat zidane("Zidane", 150);
	zidane.signForm(ffix);
};

void instantiateBureaucratOverGradeLimitsTest(void){
	// Bureaucrat zidane("Zidane", 188); // try to instantiate the class without the try block will reproduce an abort trap
	try {
		Bureaucrat zidane("Zidane", 188);
	}
	catch (const Bureaucrat::AtConstructionGradeTooHighException& e){
		std::cout << RED << e.what() << DFT << std::endl;
	}
	catch (const Bureaucrat::AtConstructionGradeTooLowException& e){
		std::cout << RED << e.what() << DFT << std::endl;
	}
}

void instantiateFormOverGradeLimitsTest(void){
	// Form ffix("FFIX", 188, 200); // try to instantiate the class without the try block will reproduce an abort trap
	try {
		Form ffix("FFIX", 188, 200);
	}
	catch (const Form::AtConstructionGradeTooHighException& e){
		std::cout << RED << e.what() << DFT << std::endl;
	}
	catch (const Form::AtConstructionGradeTooLowException& e){
		std::cout << RED << e.what() << DFT << std::endl;
	}
}

int main(void) {
	beSignedFormTest();
	signFormTest();
	bureaucratUnderGradeTest();
	instantiateBureaucratOverGradeLimitsTest();
	instantiateFormOverGradeLimitsTest();
}