
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public:
        Form(void);
        Form(std::string name, int toSign, int toExecute);
        Form(const Form& from);
        Form& operator=(const Form& rhs);
        ~Form(void);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("The current grade is too high, the maximum grade possible is 1.");
                }
        };
		class GradeTooLowException : public std::exception {
            public:
                explicit GradeTooLowException(const Form& Form) : _grade(Form._gradeToSign) {};

                virtual const char* what() const throw() {
                    std::string returnMsg = "Bureaucrat grade is under the minimum acceptable value to sign, which is ";
                    returnMsg += std::to_string(_grade);
                    returnMsg += ".";
                    return (returnMsg.c_str());
                }
            private:
                int         _grade;
        };
        std::string getName(void) const;
        bool        getSigned(void) const;
        int         getGradeToSign(void) const;
        int         getGradeToExecute(void) const;
        void        beSigned(Bureaucrat& Bureaucrat);

    private:
        const std::string   _name;
        bool                _signed;
		const int           _gradeToSign;
		const int           _gradeToExecute;

};

std::ostream& operator<<(std::ostream& o, const Form& Form);

#endif

