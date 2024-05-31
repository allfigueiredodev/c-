/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:22:07 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/30 19:45:27 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Cat::Cat(void) : type("Cat") {
	std::cout << "Cat class default constructor called." << std::endl;
	_catBrain = new Brain();
};

Cat::~Cat(void) {
	std::cout << "Cat class destructor called." << std::endl;
	delete _catBrain;
};

Cat::Cat(const Cat& Cat) {
	std::cout << "Cat class copy constructor called." << std::endl;
	this->type = Cat.type;
	_catBrain = new Brain();
	*_catBrain = *(Cat._catBrain); 
};

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat class copy assign operator called." << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		_catBrain = new Brain();
		*_catBrain = *(rhs._catBrain);
	}
	return (*this);
};

std::string Cat::getType(void) const {
	return (this->type);
};

void Cat::makeSound(void) const {
	std::cout << "MEEOOOOOOOW" << std::endl;
}