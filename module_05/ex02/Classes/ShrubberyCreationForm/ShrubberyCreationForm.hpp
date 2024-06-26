/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:24:39 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:24:41 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Bureaucrat.h"
#include "Classes/AForm/AForm.hpp"
#include "Classes/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& ShrubberyCreationForm);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        ~ShrubberyCreationForm(void);
        
        void    execute(Bureaucrat const & executor) const;

        std::string getTarget(void) const;
    class FailToOpenFileException : public std::exception {
        
        public:
            virtual const char* what() const throw();
            
    };

    private:
        std::string _target;

};

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& ShrubberyCreationForm);

#endif

