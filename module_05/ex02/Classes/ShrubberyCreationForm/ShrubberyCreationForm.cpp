#include "Bureaucrat.h"
#include "Classes/AForm/AForm.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

// CANONICAL CONSTRUCTORS/DESTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm(void) :  AForm("Shrubbery Form", 145, 137) {
    std::cout << "ShrubberyCreationForm class default constructor called." << std::endl;
    _target = "Home";
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm("Shrubbery Form", 145, 137) {
    std::cout << "ShrubberyCreationForm class default constructor called." << std::endl;
    _target = target;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ShrubberyCreationForm) {
    std::cout << "ShrubberyCreationForm class copy constructor called." << std::endl;
    *this = ShrubberyCreationForm;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    std::cout << "ShrubberyCreationForm class copy assign operator called." << std::endl;
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm class destructor called." << std::endl;
};

// METHODS

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream outfile((this->getTarget() + "_shrubbery").data());
	try {
        if (outfile.fail() || executor.getGrade() < this->getGradeToExecute())
            throw FailToOpenFileException();
    }
    catch (const FailToOpenFileException& e) {
        std::cerr << RED << e.what() << DFT << std::endl;
    }
    outfile << "test" << std::endl;
    outfile.close();
};

// GETTERS/SETTERS

std::string ShrubberyCreationForm::getTarget(void) const {
    return (this->_target);
};

//EXCEPTIONS

const char* ShrubberyCreationForm::FailToOpenFileException::what() const throw () {
    return ("Fail creating the file");
}

// OPERATOR OVERLOADS

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& ShrubberyCreationForm) {
    o << BLUE << ShrubberyCreationForm.getName() << DFT
    << "\n" << "Signed: " << ShrubberyCreationForm.getSigned() << DFT
    << "\n" << "Grade to sign: " << ShrubberyCreationForm.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << ShrubberyCreationForm.getGradeToExecute() << DFT;
	return (o);
};