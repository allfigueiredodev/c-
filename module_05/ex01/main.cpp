/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:19:32 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/24 19:49:38 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// Bureaucrat zidane("Zidane", 188); // instantiate the class without the try block will reproduce an abort trap
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
	// Form ffix("FFIX", 188, 200); // instantiate the class without the try block will reproduce an abort trap
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
	std::cout << CYAN << "***BE SIGNED FORM TEST***" << DFT << std::endl;
	beSignedFormTest();
	std::cout << std::endl;
	std::cout << CYAN << "***SIGN FORM TEST***" << DFT << std::endl;
	signFormTest();
	std::cout << std::endl;
	std::cout << CYAN << "***BUREAUCRAT UNDER GRADE TEST***" << DFT << std::endl;
	bureaucratUnderGradeTest();
	std::cout << std::endl;
	std::cout << CYAN << "***INSTANTIATE BUREAUCRAT OVER GRADE LIMITS TEST***" << DFT << std::endl;
	instantiateBureaucratOverGradeLimitsTest();
	std::cout << std::endl;
	std::cout << CYAN << "***INSTANTIATE FORM OVER GRADE LIMITS TEST***" << DFT << std::endl;
	instantiateFormOverGradeLimitsTest();
}