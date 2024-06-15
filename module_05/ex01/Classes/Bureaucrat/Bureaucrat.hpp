/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:18:37 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:18:40 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Bureaucrat.h"
#include "Classes/Form/Form.hpp"

class Form;

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
                virtual const char* what() const throw() ;
        };
        class GradeTooHighException : public std::exception {
            
            public:
                virtual const char* what() const throw();
        };
        class AtConstructionGradeTooLowException : public std::exception {
            
            public:
                virtual const char* what() const throw() ;
        };
        class AtConstructionGradeTooHighException : public std::exception {
            
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string   _name;
        int                 _grade;

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& Bureaucrat);

#endif