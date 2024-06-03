
#include "PresidentialPardonForm.hpp"

// CANONICAL CONSTRUCTORS/DESTRUCTOR

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Perdon Form", 25, 5) {
    std::cout << "PresidentialPardonForm class default constructor called." << std::endl;
    _target = "Allesson Figueiredo";
};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Perdon Form", 25, 5) {
    std::cout << "PresidentialPardonForm class parametirezed constructor called." << std::endl;
    _target = target;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PresidentialPardonForm) {
    std::cout << "PresidentialPardonForm class copy constructor called." << std::endl;
    *this = PresidentialPardonForm;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    std::cout << "PresidentialPardonForm class copy assign operator called." << std::endl;
    if (this != &rhs){
        this->_target = rhs.target;
    }
    return *this;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm class destructor called." << std::endl;
};

// METHODS

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    std::cout << CYAN << _target << "has been pardoned by Zaphod Beeblebrox."
    << DFT << std::endl; 
};

