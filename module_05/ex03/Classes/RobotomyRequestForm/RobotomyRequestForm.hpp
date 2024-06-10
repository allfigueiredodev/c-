
#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Bureaucrat.h"
#include "Classes/AForm/AForm.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& RobotomyRequestForm);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm(void);
        void    execute(Bureaucrat const & executor) const;

        class RobotomizeFailedException : public std::exception {
            
            public:
                virtual const char* what() const throw();
        };

    private:
        std::string _target;

};

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& RobotomyRequestForm);

#endif

