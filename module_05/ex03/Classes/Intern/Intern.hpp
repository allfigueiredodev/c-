/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:26:15 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:26:17 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        AForm* makeForm(std::string name, std::string target); // try run this as private and check if any test breaks

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