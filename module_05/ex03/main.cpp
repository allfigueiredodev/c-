/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:27:13 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:27:15 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/AForm/AForm.hpp"
#include "Classes/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Classes/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Classes/Intern/Intern.hpp"

void	SubjectTest(void) {
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << GREEN << rrf->getName() << DFT << std::endl;
	delete rrf;
};

void	InternMakePresidentialPardonFormTest(void){
	Intern someRandomIntern;
	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Allesson");
	std::cout << GREEN << ppf->getName() << DFT << std::endl;
	delete ppf;
};

void	InternMakeShrubberyCreationFormTest(void){
	Intern someRandomIntern;
	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	std::cout << GREEN << scf->getName() << DFT << std::endl;
	delete scf;
};

void	BureaucratSignInternFormsTest(void){
	Intern someRandomIntern;
	Bureaucrat theBureacucrat("The Bureaucrat", 1);
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Allesson");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	rrf->beSigned(theBureacucrat);
	ppf->beSigned(theBureacucrat);
	scf->beSigned(theBureacucrat);
	theBureacucrat.executeForm(*rrf);
	theBureacucrat.executeForm(*ppf);
	theBureacucrat.executeForm(*scf);
	delete rrf;
	delete ppf;
	delete scf;
};

void	formNotRecognizedTest(void){
	Intern someRandomIntern;
	Bureaucrat theBureacucrat("The Bureaucrat", 1);
	AForm* nrf;
	nrf = someRandomIntern.makeForm("weird form", "Bender");
	delete nrf;
};

int main(void) {
	std::cout << CYAN << "***SUBJECT TEST***" << DFT << std::endl;	
	SubjectTest();
	std::cout << std::endl;
	std::cout << CYAN << "***INTERN MAKE PRESIDENTIAL PARDON FORM TEST***" << DFT << std::endl;	
	InternMakePresidentialPardonFormTest();
	std::cout << std::endl;
	std::cout << CYAN << "***INTERN MAKE SHRUBBERY CREATION FORM TEST***" << DFT << std::endl;	
	InternMakeShrubberyCreationFormTest();
	std::cout << std::endl;
	std::cout << CYAN << "***BUREAUCRAT SIGN INTERN FORMS TEST***" << DFT << std::endl;	
	BureaucratSignInternFormsTest();
	std::cout << std::endl;
	std::cout << CYAN << "***NOT RECOGNIZED FORM TEST***" << DFT << std::endl;	
	formNotRecognizedTest();
	std::cout << std::endl;
}