#include "Bureaucrat.h"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45) {
    std::cout << "RobotomyRequestForm class default constructor called." << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45) {
    std::cout << "RobotomyRequestForm class parametarized constructor called." << std::endl;
    _target = target;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& RobotomyRequestForm) {
    std::cout << "RobotomyRequestForm class copy constructor called." << std::endl;
    *this = RobotomyRequestForm;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    std::cout << "RobotomyRequestForm class copy assign operator called." << std::endl;
    if (this != &rhs){
        this->target = rhs.target;
    }
    return *this;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm class destructor called." << std::endl;
};

// METHOD

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    try {
        if (std::rand() % 2 == 0){
            std::cout << GREEN << "*Makes some drilling noises*\n"
            << this->_target << " has been robotomized successfully"  
            << DFT << std::endl;
        }
        else
            throw RobotomyRequestForm::RobotomizeFailedException();
    }
    catch (const RobotomyRequestForm::RobotomizedFailedException& e) {
        std::cerr << RED << e.what() << DFT << std::endl;
    }
};

// EXCEPTIONS

const char* RobotomyRequestForm::RobotomizeFailedException::what() cons throw {
    return ("The robotomotization has failed.");
}
