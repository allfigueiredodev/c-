/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:25:37 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:25:40 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.h"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    public:
        AForm(void);
        AForm(std::string name, int toSign, int toExecute);
        AForm(const AForm& from);
        AForm& operator=(const AForm& rhs);
        virtual ~AForm(void);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
		class GradeTooLowException : public std::exception {
            public:
                explicit GradeTooLowException(const AForm& AForm);
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
        std::string     getName(void) const;
        bool            getSigned(void) const;
        int             getGradeToSign(void) const;
        int             getGradeToExecute(void) const;
        void            beSigned(Bureaucrat& Bureaucrat);
        virtual void    execute(Bureaucrat const & executor) const = 0;	

    private:
        const std::string   _name;
        bool                _signed;
		const int           _gradeToSign;
		const int           _gradeToExecute;

};

std::ostream& operator<<(std::ostream& o, const AForm& AForm);

#endif

