/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:18:57 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:19:03 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Classes/Form/Form.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

Form::Form(void) : _name("Empty Form"), _signed(false), _gradeToSign(20), _gradeToExecute(5) {
    std::cout << "Form class default constructor called." << std::endl;
};

Form::Form(std::string name, const int toSign, const int toExecute) : _name(name), _signed(false), _gradeToSign(toSign), _gradeToExecute(toExecute) {
    std::cout << "Form class parameterized constructor called." << std::endl;
	if (_gradeToSign < 1)
		throw Form::AtConstructionGradeTooHighException();
	else if (_gradeToSign > 150)
		throw Form::AtConstructionGradeTooLowException();
	if (toExecute < 1)
		throw Form::AtConstructionGradeTooHighException();
	else if (toExecute > 150)
		throw Form::AtConstructionGradeTooLowException();
};

Form::Form(const Form& from) : _gradeToSign(from._gradeToSign), _gradeToExecute(from._gradeToExecute) {
    std::cout << "Form class copy constructor called." << std::endl;
    *this = from;
};

Form& Form::operator=(const Form& rhs) {
    std::cout << "Form class copy assign operator called." << std::endl;
    if (this != &rhs){
        (int&)this->_gradeToSign = rhs._gradeToSign;
        (int&)this->_gradeToExecute = rhs._gradeToExecute;
    }
    return *this;
};

Form::~Form(void) {
    std::cout << "Form class destructor called." << std::endl;
};

std::string Form::getName(void) const {
    return (this->_name);
};

bool        Form::getSigned(void) const {
    return (this->_signed);
};

int   Form::getGradeToSign(void) const {
    return (this->_gradeToSign);
};

int   Form::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
};

void        Form::beSigned(Bureaucrat& Bureaucrat) {
    try {
        if(Bureaucrat.getGrade() > this->getGradeToSign())
            throw Form::GradeTooLowException(*this);
        else if (!this->_signed) {
            this->_signed = true;
			std::cout << GREEN << "Form " << this->getName() << " signed." << DFT << std::endl;
		}  
		else
			std::cout << YELLOW << "Form " << this->getName() << " is signed already." << DFT << std::endl;

    }
    catch (const Form::GradeTooLowException& e) {
        std::cout << BLUE << Bureaucrat.getName() << DFT << " couldn't sign "
        << YELLOW << this->_name << DFT << " because: \n" 
        << RED << e.what() << DFT << std::endl;
    }
};

char const * Form::GradeTooHighException::what() const throw() {
		return ("The current grade is too high, the maximum grade possible is 1.");
};

Form::GradeTooLowException::GradeTooLowException(const Form& Form) : _grade(Form._gradeToSign) {};

char const * Form::GradeTooLowException::what() const throw() {
	static std::string returnMsg;
	std::stringstream stream;
	returnMsg = "Bureaucrat grade is under the minimum acceptable value to sign, which is ";
	stream << _grade;
	returnMsg += stream.str();
	returnMsg += ".";
	return (returnMsg.c_str());
};

const char* Form::AtConstructionGradeTooLowException::what() const throw() {
    return ("The value is over the limits, the lowest grade possible is 150.");
};

const char* Form::AtConstructionGradeTooHighException::what() const throw() {
    return ("The value is over the limits, the highest grade possible is 1.");
};

std::ostream& operator<<(std::ostream& o, const Form& Form) {
    o << BLUE << Form.getName() << DFT
    << "\n" << "Signed: " << Form.getSigned() << DFT
    << "\n" << "Grade to sign: " << Form.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << Form.getGradeToExecute() << DFT;
	return (o);
};

