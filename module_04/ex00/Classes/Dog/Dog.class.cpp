/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:22:07 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/05 20:59:02 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Dog::Dog(void) : _type("Dog") {
	std::cout << "Dog class default constructor called." << std::endl;
};

Dog::~Dog(void) {
	std::cout << "Dog class destructor called." << std::endl;
};

Dog::Dog(const Dog& Dog) {
	std::cout << "Dog class copy constructor called." << std::endl;
	*this = Dog;
};

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog class copy assign operator called." << std::endl;
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return (*this);
};

std::string Dog::getType(void) const {
	return (this->_type);
};

void Dog::makeSound(void) const {
	std::cout << "WOOF!!!WOOF!!!" << std::endl;
}
