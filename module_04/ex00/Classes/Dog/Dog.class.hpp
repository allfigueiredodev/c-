/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:18:25 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/05 20:58:43 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "Polymorphism.h"

class Dog : public Animal {

	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog& Dog);
		Dog& operator=(const Dog& rhs);
		std::string getType(void) const;
		void makeSound(void) const;
	
	private:
		std::string _type;
		
};

#endif