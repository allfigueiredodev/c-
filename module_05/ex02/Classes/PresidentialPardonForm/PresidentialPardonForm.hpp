
#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

class PresidentialPardonForm {

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& PresidentialPardonForm);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm(void);
        void    execute(Bureaucrat const & executor) const;

    private:
        std::string target;

};

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& PresidentialPardonForm);

#endif
