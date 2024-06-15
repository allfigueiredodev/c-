/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:19:09 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:19:13 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public:
        Form(void);
        Form(std::string name, const int toSign, const int toExecute);
        Form(const Form& from);
        Form& operator=(const Form& rhs);
        ~Form(void);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
		class GradeTooLowException : public std::exception {
            public:
                explicit GradeTooLowException(const Form& Form);
                virtual const char* what() const throw();

            private:
                int         _grade;
        };
		class AtConstructionGradeTooLowException : public std::exception {
            
            public:
                virtual const char* what() const throw() ;
        };
        class AtConstructionGradeTooHighException : public std::exception {
            
            public:
                virtual const char* what() const throw();
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

