/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:18:25 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/31 07:54:29 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "Polymorphism.h"

class Dog : public AAnimal {

	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog& Dog);
		Dog& operator=(const Dog& rhs);
		std::string getType(void) const;
		void makeSound(void) const;
	
	private:
		std::string type;
		Brain* _dogBrain;
		
};

#endif