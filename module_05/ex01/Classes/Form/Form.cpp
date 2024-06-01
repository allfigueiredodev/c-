#include "Bureaucrat.h"
#include "Classes/Form/Form.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

Form::Form(void) : _name("Empty Form"), _signed(false), _gradeToSign(20), _gradeToExecute(5) {
    std::cout << "Form class default constructor called." << std::endl;
};

Form::Form(std::string name, int toSign, int toExecute) : _name(name), _signed(false), _gradeToSign(toSign), _gradeToExecute(toExecute) {
    std::cout << "Form class parameterized constructor called." << std::endl;
};

Form::Form(const Form& Form) {
    std::cout << "Form class copy constructor called." << std::endl;
    *this = Form;
};

Form& Form::operator=(const Form& rhs) {
    std::cout << "Form class copy assign operator called." << std::endl;
    if (this != &rhs){
        //...
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
        std::cout << RED << e.what() << DFT << std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Form& Form) {
    o << BLUE << Form.getName() << DFT
    << "\n" << "Signed: " << Form.getSigned() << DFT
    << "\n" << "Grade to sign: " << Form.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << Form.getGradeToExecute() << DFT;
	return (o);
};