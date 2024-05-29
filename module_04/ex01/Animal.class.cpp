/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:51:29 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/28 20:21:29 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Animal::Animal(void) {
	std::cout << "Animal class default constructor called." << std::endl;
};

Animal::~Animal(void) {
	std::cout << "Animal class destructor called." << std::endl;
};

Animal::Animal(const Animal& Animal) {
	std::cout << "Animal class copy constructor called." << std::endl;
	*this = Animal;
};

Animal& Animal::operator=(const Animal& rhs) {
	std::cout << "Animal class copy assign operator called." << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
};

void Animal::makeSound(void) const {
	std::cout << "*unrecognized animal noise*" << std::endl;
}

std::string Animal::getType(void) const {
	return (this->type);
};

void Animal::setType(std::string animalType) {
	this->type = animalType;	
};
