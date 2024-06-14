
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(void) : _name("Allesson Figueiredo"), _grade(1) {
    std::cout << "Bureaucrat class default constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    std::cout << "Bureaucrat class named constructor called." << std::endl;    
    try {
        if (grade > 150)
            throw Bureaucrat::AtConstructionGradeTooLowException();
        else if (grade < 1)
            throw Bureaucrat::AtConstructionGradeTooHighException();
        else
            _grade = grade;
    }
    catch (const Bureaucrat::AtConstructionGradeTooLowException& e) {
        std::cout << RED << e.what() << DFT << std::endl;
    }
    catch (const Bureaucrat::AtConstructionGradeTooHighException& e) {
        std::cout << RED << e.what() << DFT << std::endl;
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
