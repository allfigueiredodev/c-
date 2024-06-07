/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:22:07 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/07 00:51:16 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Dog::Dog(void) : type("Dog") {
	std::cout << "Dog class default constructor called." << std::endl;
	_dogBrain = new Brain();
};

Dog::~Dog(void) {
	std::cout << "Dog class destructor called." << std::endl;
	delete _dogBrain;
};

Dog::Dog(const Dog& Dog) {
	std::cout << "Dog class copy constructor called." << std::endl;
	_dogBrain = new Brain();
	*_dogBrain = *(Dog._dogBrain);
};

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog class copy assign operator called." << std::endl;
	if (this != &rhs){
		this->type = rhs.type;
		_dogBrain = new Brain();
		*_dogBrain = *(rhs._dogBrain);
	}
	return (*this);
};

std::string Dog::getType(void) const {
	return (this->type);
};

void Dog::makeSound(void) const {
	std::cout << "WOOF!!!WOOF!!!" << std::endl;
}

void Dog::tellIdeas(void) {
	int i = 0;
	
	while (this->_dogBrain->getIdeas(i++).empty() == false)
		std::cout << GREEN << this->_dogBrain->getIdeas(i) << DFT << std::endl; 	
};
