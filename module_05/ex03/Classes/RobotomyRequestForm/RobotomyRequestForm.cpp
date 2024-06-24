/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:26:38 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/24 19:57:45 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45) {
    std::cout << "RobotomyRequestForm class default constructor called." << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45) {
    std::cout << "RobotomyRequestForm class parametarized constructor called." << std::endl;
    _target = target;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& RobotomyRequestForm) : AForm(RobotomyRequestForm) {
    std::cout << "RobotomyRequestForm class copy constructor called." << std::endl;
    *this = RobotomyRequestForm;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    std::cout << "RobotomyRequestForm class copy assign operator called." << std::endl;
    if (this != &rhs){
        this->_target = rhs._target;
    }
    return *this;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm class destructor called." << std::endl;
};

// METHOD

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    try {
        if (executor.getGrade() < this->getGradeToExecute() && this->getSigned() && std::rand() % 2 == 0) {
            std::cout << GREEN << "*Makes some drilling noises*\n"
            << this->_target << ", has been robotomized successfully"  
            << DFT << std::endl;
        }
        else
            throw RobotomyRequestForm::RobotomizeFailedException();
    }
    catch (const RobotomyRequestForm::RobotomizeFailedException& e) {
        std::cerr << RED << e.what() << DFT << std::endl;
    }
};

// EXCEPTIONS

const char* RobotomyRequestForm::RobotomizeFailedException::what() const throw () {
    return ("The robotomotization has failed.");
}

// OPERATOR OVERLOADS

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& RobotomyRequestForm) {
    o << BLUE << RobotomyRequestForm.getName() << DFT
    << "\n" << "Signed: " << RobotomyRequestForm.getSigned() << DFT
    << "\n" << "Grade to sign: " << RobotomyRequestForm.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << RobotomyRequestForm.getGradeToExecute() << DFT;
	return (o);
};