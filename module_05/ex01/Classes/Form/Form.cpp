#include "Bureaucrat.h"
#include "Classes/Form/Form.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include <cstdlib>

Form::Form(void) : _name("Empty Form"), _signed(false), _gradeToSign(20), _gradeToExecute(5) {
    std::cout << "Form class default constructor called." << std::endl;
};

Form::Form(std::string name, int toSign, int toExecute) : _name(name), _signed(false), _gradeToSign(toSign), _gradeToExecute(toExecute) {
    std::cout << "Form class parameterized constructor called." << std::endl;
}; // maybe there is a problem here, try to instantiate with more than 150 or less than 1 to see what happens.

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
        else    
            this->_signed = true;
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

explicit Form::GradeTooLowException(const Form& Form) : _grade(Form._gradeToSign) {};

char const * Form::GradeTooLowException::what() const throw() {

	std::string returnMsg = "Bureaucrat grade is under the minimum acceptable value to sign, which is ";
	returnMsg += std::to_string(_grade);
	returnMsg += ".";
	return (returnMsg.c_str());
};

std::ostream& operator<<(std::ostream& o, const Form& Form) {
    o << BLUE << Form.getName() << DFT
    << "\n" << "Signed: " << Form.getSigned() << DFT
    << "\n" << "Grade to sign: " << Form.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << Form.getGradeToExecute() << DFT;
	return (o);
};

