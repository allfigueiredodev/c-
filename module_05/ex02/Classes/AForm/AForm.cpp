#include "Bureaucrat.h"
#include "Classes/AForm/AForm.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

// CANONICAL CONSTRUCTORS/DESTRUCTOR

AForm::AForm(void) : _name("Empty AForm"), _signed(false), _gradeToSign(20), _gradeToExecute(5) {
    std::cout << "AForm class default constructor called." << std::endl;
};

AForm::AForm(std::string name, int toSign, int toExecute) : _name(name), _signed(false), _gradeToSign(toSign), _gradeToExecute(toExecute) {
    std::cout << "AForm class parameterized constructor called." << std::endl;
};

AForm::AForm(const AForm& from) : _gradeToSign(from._gradeToSign), _gradeToExecute(from._gradeToExecute) {
    std::cout << "AForm class copy constructor called." << std::endl;
    *this = from;
};

AForm::~AForm(void) {
    std::cout << "AForm class destructor called." << std::endl;
};

AForm& AForm::operator=(const AForm& rhs) {
    std::cout << "AForm class copy assign operator called." << std::endl;
    if (this != &rhs){
        (int&)this->_gradeToSign = rhs._gradeToSign;
        (int&)this->_gradeToExecute = rhs._gradeToExecute;
    }
    return *this;
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

void        AForm::beSigned(Bureaucrat& Bureaucrat) {
    try {
        if(Bureaucrat.getGrade() > this->getGradeToSign())
            throw AForm::GradeTooLowException(*this);
        else    
            this->_signed = true;
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cout << BLUE << Bureaucrat.getName() << DFT << " couldn't sign "
        << YELLOW << this->_name << DFT << " because: \n" 
        << RED << e.what() << DFT << std::endl;
    }
}

// OPERATOR OVERLOADS

std::ostream& operator<<(std::ostream& o, const AForm& AForm) {
    o << BLUE << AForm.getName() << DFT
    << "\n" << "Signed: " << AForm.getSigned() << DFT
    << "\n" << "Grade to sign: " << AForm.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << AForm.getGradeToExecute() << DFT;
	return (o);
};

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw() {
    return ("The current grade is too high, the maximum grade possible is 1.");
};

const char* AForm::GradeTooLowException::what() const throw() {
    std::string returnMsg = "Bureaucrat grade is under the minimum acceptable value to sign, which is ";
    returnMsg += std::to_string(_grade);
    returnMsg += ".";
    return (returnMsg.c_str());
}