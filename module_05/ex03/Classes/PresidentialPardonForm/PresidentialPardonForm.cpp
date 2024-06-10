
#include "PresidentialPardonForm.hpp"

// CANONICAL CONSTRUCTORS/DESTRUCTOR

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5) {
    std::cout << "PresidentialPardonForm class default constructor called." << std::endl;
    _target = "Allesson Figueiredo";
};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5) {
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
        this->_target = rhs._target;
    }
    return *this;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm class destructor called." << std::endl;
};

// METHODS

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		if (executor.getGrade() < this->getGradeToExecute() && this->getSigned())
	    	std::cout << GREEN << _target << ", has been pardoned by Zaphod Beeblebrox." << DFT << std::endl;
		else {
			throw PresidentialPardonForm::FailToPardonException();
		}
	}
	catch (const PresidentialPardonForm::FailToPardonException& e) {
		std::cout << RED << e.what() << _target
		<< ", is on the death row" << DFT << std::endl;
	}
};

// EXCEPTIONS

const char* PresidentialPardonForm::FailToPardonException::what() const throw () {
	return ("Unforgivable... ");
};

// OPERATOR OVEERLOADS

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& PresidentialPardonForm) {
    o << BLUE << PresidentialPardonForm.getName() << DFT
    << "\n" << "Signed: " << PresidentialPardonForm.getSigned() << DFT
    << "\n" << "Grade to sign: " << PresidentialPardonForm.getGradeToSign() << DFT
    << "\n" << "Grade to execute: " << PresidentialPardonForm.getGradeToExecute() << DFT;
	return (o);
};