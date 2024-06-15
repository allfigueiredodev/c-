/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:18:25 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:21:37 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/Form/Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Allesson Figueiredo"), _grade(1) {
    std::cout << "Bureaucrat class default constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    std::cout << "Bureaucrat class named constructor called." << std::endl;    
	if (grade > 150)
		throw Bureaucrat::AtConstructionGradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::AtConstructionGradeTooHighException();
	else
		_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& Bureaucrat) {
    std::cout << "Bureaucrat class copy constructor called." << std::endl;
    *this = Bureaucrat;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
    std::cout << "Bureaucrat class copy assign operator called." << std::endl;
    if (this != &rhs){
        (std::string)this->_name = rhs._name;
        this->_grade = rhs._grade;
    }
    return *this;
};

Bureaucrat::~Bureaucrat(void){
    std::cout << "Bureaucrat class destructor called." << std::endl;
};

std::string Bureaucrat::getName(void) const {
    return (this->_name);    
}

int         Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

void        Bureaucrat::incrementGrade(void) {
    try {
        if (this->_grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        else {
            this->_grade = this->_grade - 1;
            std::cout << CYAN << "Bureaucrat " << this->_name
            << " grade has increased to " << this->_grade << std::endl;
        }
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << RED << e.what() << DFT << std::endl;
    }
};

void        Bureaucrat::decrementGrade(void) {
    try {
        if (this->_grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();      
        else {
            this->_grade = this->_grade + 1;
            std::cout << MAGENTA << "Bureaucrat " << this->_name
            << " grade has decreased to " << this->_grade << std::endl;
        }

    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << RED << e.what() << DFT << std::endl;
    }
};

void        Bureaucrat::signForm(Form& Form) {
    try {
        if (!Form.getSigned() && this->getGrade() < Form.getGradeToSign()){
			Form.beSigned(*this);
            std::cout << BLUE << this->getName() << DFT << " signed " << GREEN << Form.getName() << DFT << std::endl;
		}
        else if (Form.getSigned())
			std::cout << YELLOW << "Form " << Form.getName() << " is signed already." << DFT << std::endl;
		else
            throw Form::GradeTooLowException(Form);
    }
    catch (const Form::GradeTooLowException& e) {
        std::cout << BLUE << this->_name << DFT << " couldn't sign "
        << YELLOW << Form.getName() << DFT << " because: \n" 
        << RED << e.what() << DFT << std::endl;
    }
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("The value will decrement over the limits, the lowest grade possible is 150.");
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("The value will increment over the limits, the highest grade possible is 1.");
};

const char* Bureaucrat::AtConstructionGradeTooLowException::what() const throw() {
    return ("The value is over the limits, the lowest grade possible is 150.");
};

const char* Bureaucrat::AtConstructionGradeTooHighException::what() const throw() {
    return ("The value is over the limits, the highest grade possible is 1.");
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& Bureaucrat) {
    o << BLUE << Bureaucrat.getName() << DFT << ", bureaucrat grade " << GREEN << Bureaucrat.getGrade() << DFT << ".";
	return (o);
};
