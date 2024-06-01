
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"
#include "Classes/Form/Form.hpp"

class Form {

    public:
        Form(void);
        Form(std::string name, int toSign, int toExecute);
        Form(const Form& Form);
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
                explicit GradeTooLowException(const Form& Form) : _gradeToSign(Form._gradeToSign) {};

                virtual const char* what() const throw() {
                    std::string returnMsg = "The grade is under the minimum acceptable value, which is ";
                    returnMsg += std::to_string(_gradeToSign);
                    returnMsg += " .";
                    return (returnMsg.c_str());
                }
            private:
                int _gradeToSign;
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

