
#include "Bureaucrat.h"
#include "Classes/Form/Form.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Allesson Figueiredo"), _grade(1) {
    std::cout << "Bureaucrat class default constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    std::cout << "Bureaucrat class named constructor called." << std::endl;    
    try {
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            _grade = grade;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
};

Bureaucrat::Bureaucrat(const Bureaucrat& Bureaucrat){
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
        else
            this->_grade = this->_grade - 1;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << RED << e.what() << DFT << std::endl;
    }
};

void        Bureaucrat::decrementGrade(void) {
    try {
        if (this->_grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();      
        else
            this->_grade = this->_grade + 1;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << RED << e.what() << DFT << std::endl;
    }
};

void        Bureaucrat::signForm(Form& Form) {
    try {
        if (Form.getSigned())
            std::cout << BLUE << this->getName() << DFT << " signed " << GREEN << Form.getName() << DFT << std::endl;
        else
            throw Form::GradeTooLowException(Form);
    }
    catch (const Form::GradeTooLowException& e) {
        std::cout << BLUE << this->_name << DFT << " couldn't sign "
        << YELLOW << Form.getName() << DFT << " because: \n" 
        << RED << e.what() << DFT << std::endl;
    }
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& Bureaucrat) {
    o << BLUE << Bureaucrat.getName() << DFT << ", bureaucrat grade " << GREEN << Bureaucrat.getGrade() << DFT << ".";
	return (o);
};