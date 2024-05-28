/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:34:04 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/28 20:38:58 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
#define ANIMAL_CLASS_HPP

#include "Polymorphism.h"

class Animal {
	
	public:
		Animal(void);
		~Animal(void);
		Animal(const Animal& Animal);
		Animal& operator=(const Animal& rhs);
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
		void setType(std::string type);
	
	protected:
		std::string type;
		
};

#endif