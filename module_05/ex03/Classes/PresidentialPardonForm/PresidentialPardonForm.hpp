/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:26:28 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/14 23:26:30 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Bureaucrat.h"
#include "Classes/AForm/AForm.hpp"
#include "Classes/Bureaucrat/Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& PresidentialPardonForm);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm(void);
        void    execute(Bureaucrat const & executor) const;
		class FailToPardonException {

			public:
				virtual const char* what() const throw();
		};

    private:
        std::string _target;

};

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& PresidentialPardonForm);

#endif
