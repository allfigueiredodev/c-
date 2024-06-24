/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:18:03 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/24 19:34:56 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

void	defaultConstructorTest(void){
	Bureaucrat bZero;
	std::cout << CYAN << "The standard bureaucrat name is: " << bZero.getName()
	<< " and his standard grade is: " << bZero.getGrade() << DFT << std::endl;
}

void	decrementGradeOverLimitTest(void){
	Bureaucrat bOne("bOne", 2);
	bOne.incrementGrade();
	bOne.incrementGrade();
}

void	incrementGradeOverLimitTest(void){
	Bureaucrat bTwo("bTwo", 149);
	bTwo.decrementGrade();
	bTwo.decrementGrade();
}

void	instantiateOverLimitsTest(void){
	Bureaucrat over("OVER", 160);
	Bureaucrat under("UNDER", 0); 
}

void	ostreamOverloadTest(void){
	Bureaucrat testStream("Test Stream", 75);
	std::cout << testStream << std::endl;
}

int main(void) {
	std::cout << GREEN << "***DEFAULT CONSTRUCTOR TEST***" << DFT << std::endl;
	defaultConstructorTest();
	std::cout << GREEN << "***DECREMENT GRADE OVER LIMIT TEST***" << DFT << std::endl;
	decrementGradeOverLimitTest();
	std::cout << GREEN << "***INCREMENT GRADE OVER LIMIT TEST***" << DFT << std::endl;
	incrementGradeOverLimitTest();
	std::cout << GREEN << "***INSTANTIATE OVER LIMITS TEST***" << DFT << std::endl;
	try {
		instantiateOverLimitsTest();
	}
	catch (const Bureaucrat::AtConstructionGradeTooLowException& e) {
        std::cout << RED << e.what() << DFT << std::endl;
	}
	std::cout << GREEN << "***OSTREAM OVER LOAD TEST***" << DFT << std::endl;
	ostreamOverloadTest();
}