
#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.h"
#include "Classes/AForm/AForm.hpp"
#include "Classes/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Classes/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

class Intern {

    public:

        Intern(void);
        Intern(const Intern& Intern);
        Intern& operator=(const Intern& rhs);
        ~Intern(void);
        AForm* makeForm(std::string name, std::string target);

    private:

        typedef struct s_forms {
            std::string key;
            AForm*    (Intern::*fptr)(const std::string& target) const;
        }   t_forms;
        
        t_forms _execForms[3];

        AForm* _PresidentialPardonForm(const std::string& target) const;
        AForm* _RobotomyRequestForm(const std::string& target) const;
        AForm* _ShrubberyCreationForm(const std::string& target) const;

};

#endif