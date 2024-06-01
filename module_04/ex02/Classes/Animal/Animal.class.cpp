/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:51:29 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/31 07:52:43 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal class default constructor called." << std::endl;
};

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal class destructor called." << std::endl;
};

AAnimal::AAnimal(const AAnimal& AAnimal) {
	std::cout << "AAnimal class copy constructor called." << std::endl;
	*this = AAnimal;
};

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	std::cout << "AAnimal class copy assign operator called." << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
};

// void AAnimal::makeSound(void) const {
// 	std::cout << "*unrecognized animal noise*" << std::endl;
// }

std::string AAnimal::getType(void) const {
	return (this->type);
};

void AAnimal::setType(std::string animalType) {
	this->type = animalType;	
};
