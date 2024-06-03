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

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) {
    try {
        std::ofstream outfile(this->getTarget() + "_shrubbery");
        if (outfile.fail())
            throw FailToOpenFileException();
    }
    catch (const FailToOpenFileException& e) {
        std::cerr << RED << e.what() << DFT << std::endl;
    }
    oufile << ASCCI_TREE << std::endl;
    oufile.close();
};

// GETTERS/SETTERS

std::string ShrubberyCreationForm::getTarget(void) {
    return (this->_target);
};

//EXCEPTIONS

const char* ShrubberyCreationForm::FailToOpenFileException::what() const throw () {
    return ("Fail creating the file");
} 
