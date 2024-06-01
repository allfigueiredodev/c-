
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Bureaucrat.h"
#include "Classes/Form/Form.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

class Bureaucrat {

    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& Bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat(void);
        std::string getName(void) const;
        int         getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);
        void        signForm(Form& Form);
        class GradeTooLowException : public std::exception {
            
            public:
                virtual const char* what() const throw() {
                    return ("The value will decrement over the limits, the lowest grade possible is 150.");
                }
        };
        class GradeTooHighException : public std::exception {
            
            public:
                virtual const char* what() const throw() {
                    return ("The value will increment over the limits, the highest grade possible is 1.");
                }
        };

    private:
        const std::string   _name;
        int                 _grade;

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& Bureaucrat);

#endif