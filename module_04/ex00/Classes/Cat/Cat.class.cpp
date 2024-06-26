/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:22:07 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/05 21:51:47 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Cat::Cat(void) {
	std::cout << "Cat class default constructor called." << std::endl;
	this->_type = "Cat";
};

Cat::~Cat(void) {
	std::cout << "Cat class destructor called." << std::endl;
};

Cat::Cat(const Cat& Cat) {
	std::cout << "Cat class copy constructor called." << std::endl;
	*this = Cat;
};

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat class copy assign operator called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
};

std::string Cat::getType(void) const {
	return (this->_type);
};

void Cat::makeSound(void) const {
	std::cout << "MEEOOOOOOOW" << std::endl;
}