/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:23:06 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:23:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Classes/AForm/AForm.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

// CANONICAL CONSTRUCTORS/DESTRUCTOR

AForm::AForm(void) : _name("Empty AForm"), _signed(false), _gradeToSign(20), _gradeToExecute(5) {
    std::cout << "AForm class default constructor called." << std::endl;
};

AForm::AForm(std::string name, int toSign, int toExecute) : _name(name), _signed(false), _gradeToSign(toSign), _gradeToExecute(toExecute) {
    std::cout << "AForm class parameterized constructor called." << std::endl;
	if (_gradeToSign < 1)
		throw AForm::AtConstructionGradeTooHighException();
	else if (_gradeToSign > 150)
		throw AForm::AtConstructionGradeTooLowException();
	if (toExecute < 1)
		throw AForm::AtConstructionGradeTooHighException();
	else if (toExecute > 150)
		throw AForm::AtConstructionGradeTooLowException();
};

AForm::AForm(const AForm& from) : _gradeToSign(from._gradeToSign), _gradeToExecute(from._gradeToExecute) {
    std::cout << "AForm class copy constructor called." << std::endl;
    *this = from;
};


AForm& AForm::operator=(const AForm& rhs) {
    std::cout << "AForm class copy assign operator called." << std::endl;
    if (this != &rhs){
        (int&)this->_gradeToSign = rhs._gradeToSign;
        (int&)this->_gradeToExecute = rhs._gradeToExecute;
    }
    return *this;
};

AForm::~AForm(void) {
    std::cout << "AForm class destructor called." << std::endl;
};

// GETTERS AND SETTERS

std::string AForm::getName(void) const {
    return (this->_name);
};

bool        AForm::getSigned(void) const {
    return (this->_signed);
};

int   AForm::getGradeToSign(void) const {
    return (this->_gradeToSign);
};

int   AForm::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
};

// METHODS

void       AForm::beSigned(Bureaucrat& Bureaucrat) {
    try {
        if(Bureaucrat.getGrade() > this->getGradeToSign())
            throw AForm::GradeTooLowException(*this);
        else if (!this->_signed) {
            this->_signed = true;
			std::cout << GREEN << "Form " << this->getName() << " signed." << DFT << std::endl;
		}  
		else
			std::cout << YELLOW << "Form " << this->getName() << " is signed already." << DFT << std::endl;

    }
    catch (const AForm::GradeTooLowException& e) {
        std::cout << BLUE << Bureaucrat.getName() << DFT << " couldn't sign "
        << YELLOW << this->_name << DFT << " because: \n" 
        << RED << e.what() << DFT << std::endl;
    }
};

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw() {
    return ("The current grade is too high, the maximum grade possible is 1.");
};

AForm::GradeTooLowException::GradeTooLowException(const AForm& AForm) : _grade(AForm._gradeToSign) {};

char const * AForm::GradeTooLowException::what() const throw() {
	static std::string returnMsg;
	std::stringstream stream;
	returnMsg = "Bureaucrat grade is under the minimum acceptable value to sign, which is ";
	stream << _grade;
	returnMsg += stream.str();
	returnMsg += ".";
	return (returnMsg.c_str());
};

const char* AForm::AtConstructionGradeTooLowException::what() const throw() {
    return ("The value is over the limits, the lowest grade possible is 150.");
};

const char* AForm::AtConstructionGradeTooHighException::what() const throw() {
    return ("The value is over the limits, the highest grade possible is 1.");
};

// OPERATOR OVERLOADS

std::ostream& operator<<(std::ostream& o, const AForm& AForm) {
    o << BLUE << AForm.getName() << DFT
    << "\n" << "Signed: " << AForm.getSigned() << DFT
    << "\n" << "Grade to sign: " << AForm.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << AForm.getGradeToExecute() << DFT;
	return (o);
};