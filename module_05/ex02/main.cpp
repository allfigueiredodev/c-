/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:24:57 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/24 19:53:54 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/AForm/AForm.hpp"
#include "Classes/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Classes/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

void 	PresidentialPardonFormRequiredGradesTest(void){
	std::cout << MAG_YE << "PresidentialPardonFormRequiredGradesTest" << DFT << std::endl;
	std::cout << std::endl;
	PresidentialPardonForm pardonForm("Allesson");
	std::cout << YELLOW << pardonForm << DFT << std::endl;
};

void	PresidentialPardonFormExecuteTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "PresidentialPardonFormExecuteTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne",1);
	PresidentialPardonForm pPF("Allesson");
	pPF.beSigned(bOne);
	pPF.execute(bOne);
};

void	PresidentialPardonFormLowerSignGradeTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "PresidentialPardonFormLowerSignGradeTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 150);
	PresidentialPardonForm pPF("Allesson");
	bOne.signForm(pPF);
};

void	PresidentialPardonFormLowerExecGradeTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "PresidentialPardonFormLowerExecGradeTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 6);
	PresidentialPardonForm pPF("Allesson");
	pPF.beSigned(bOne);
	pPF.execute(bOne);
};

void	ShrubberyCreationFormRequiredGradesTest(void){
	std::cout << std::endl;
	std::cout << MAG_YE << "ShrubberyCreationFormRequiredGradesTest" << DFT << std::endl;
	std::cout << std::endl;
	ShrubberyCreationForm ShrubForm("Home");
	std::cout << YELLOW << ShrubForm << DFT << std::endl;
};

void	ShrubberyCreationFormExecuteTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "ShrubberyCreationFormExecuteTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 1);
	ShrubberyCreationForm sCF("Home");
	sCF.beSigned(bOne);
	sCF.execute(bOne);
};

void	ShrubberyCreationFormLowerSignGradeTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "ShrubberyCreationFormLowerSignGradeTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 150);
	ShrubberyCreationForm sCF("Home");
	bOne.signForm(sCF);
};

void	ShrubberyCreationFormLowerExecGradeTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "ShrubberyCreationFormLowerExecGradeTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 138);
	ShrubberyCreationForm sCF("Home");
	sCF.beSigned(bOne);
	sCF.execute(bOne);
};

void	RobotomyRequestFormRequiredGradesTest(void){
	std::cout << std::endl;
	std::cout << MAG_YE << "RobotomyRequestFormRequiredGradesTest" << DFT << std::endl;
	std::cout << std::endl;
	RobotomyRequestForm RobotForm("Allesson");
	std::cout << YELLOW << RobotForm << DFT << std::endl;
};

void	RobotomyRequestFormExecuteTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "RobotomyRequestFormExecuteTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 1);
	RobotomyRequestForm rRF("Allesson");
	rRF.beSigned(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
	rRF.execute(bOne);
};

void	RobotomyRequestFormLowerSignGradeTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "RobotomyRequestFormLowerSignGradeTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 150);
	RobotomyRequestForm rRF("Allesson");
	bOne.signForm(rRF);
};

void	RobotomyRequestFormLowerExecGradeTest(){
	std::cout << std::endl;
	std::cout << MAG_YE << "RobotomyRequestFormLowerExecGradeTest" << DFT << std::endl;
	std::cout << std::endl;
	Bureaucrat bOne("bOne", 46);
	RobotomyRequestForm rRF("Allesson");
	rRF.beSigned(bOne);
	rRF.execute(bOne);
};

int main(void) {
	std::cout << CYAN << "***PRESIDENTIAL PARDON FORM TESTS***" << DFT << std::endl;
	std::cout << std::endl;
	PresidentialPardonFormRequiredGradesTest();
	PresidentialPardonFormExecuteTest();
	PresidentialPardonFormLowerSignGradeTest();
	PresidentialPardonFormLowerExecGradeTest();
	std::cout << std::endl;
	std::cout << CYAN << "***SHRUBBERY CREATION FORM TESTS***" << DFT << std::endl;
	std::cout << std::endl;
	ShrubberyCreationFormRequiredGradesTest();
	ShrubberyCreationFormExecuteTest();
	ShrubberyCreationFormLowerSignGradeTest();
	ShrubberyCreationFormLowerExecGradeTest();
	std::cout << std::endl;
	std::cout << CYAN << "***ROBOTOMY REQUEST FORM TESTS***" << DFT << std::endl;
	std::cout << std::endl;
	RobotomyRequestFormRequiredGradesTest();
	RobotomyRequestFormExecuteTest();
	RobotomyRequestFormLowerSignGradeTest();
	RobotomyRequestFormLowerExecGradeTest();
	std::cout << std::endl;
};