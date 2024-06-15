/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:26:04 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:26:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.h"
#include "Classes/Intern/Intern.hpp"
#include "Classes/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Classes/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

Intern::Intern(void) {
    std::cout << "Intern class default constructor called." << std::endl;
    this->_execForms[0].key = "presidential pardon";
    this->_execForms[0].fptr = &Intern::_PresidentialPardonForm;
    this->_execForms[1].key = "robotomy request";
    this->_execForms[1].fptr = &Intern::_RobotomyRequestForm;   
    this->_execForms[2].key = "shrubbery creation";
    this->_execForms[2].fptr = &Intern::_ShrubberyCreationForm;
};

Intern::Intern(const Intern& Intern) {
    std::cout << "Intern class copy constructor called." << std::endl;
    *this = Intern;
};

Intern& Intern::operator=(const Intern& rhs) {
    std::cout << "Intern class copy assign operator called." << std::endl;
    if (this != &rhs){
        *this = rhs;
    }
    return *this;
};

Intern::~Intern(void) {
    std::cout << "Intern class destructor called." << std::endl;
};

AForm* Intern::_PresidentialPardonForm(const std::string& target) const{
    return (new PresidentialPardonForm(target));
};

AForm* Intern::_RobotomyRequestForm(const std::string& target) const{
    return (new RobotomyRequestForm(target));
};

AForm* Intern::_ShrubberyCreationForm(const std::string& target) const{
    return (new ShrubberyCreationForm(target));
};

AForm* Intern::makeForm(std::string name, std::string target) {
    int i = 0;
    
    while(i < 3 && name != this->_execForms[i].key)
        i++;
    switch (i) {
        case 0:
            return((this->*_execForms[i].fptr)(target));
        case 1:
            return((this->*_execForms[i].fptr)(target));
        case 2:

            return((this->*_execForms[i].fptr)(target));
        default:
            std::cout << RED << "Form not found." << DFT << std::endl;
            return (NULL);
    }
}
