/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:22:07 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/07 11:13:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Cat::Cat(void) : type("Cat") {
	std::cout << "Cat class default constructor called." << std::endl;
	_catBrain = new Brain();
	for (int i = 0; i < 100; i++){
		_catBrain->setIdeas("ideia number: ", i) ;
	}
};

Cat::~Cat(void) {
	std::cout << "Cat class destructor called." << std::endl;
	delete _catBrain;
};

Cat::Cat(const Cat& Cat) {
	std::cout << "Cat class copy constructor called." << std::endl;
	this->type = Cat.type;
	std::cout << RED << "here" << DFT << std::endl; 
	// delete Cat._catBrain;
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
};

void Cat::tellIdeas(void) {
	int i = 0;
	
	while (this->_catBrain->getIdeas(i++).empty() == false)
		std::cout << GREEN << this->_catBrain->getIdeas(i) << DFT << std::endl; 	
};

void	Cat::printBrainAdress(void) {
	std::cout << &this->_catBrain << std::endl;
};

// std::ostream&	operator<<(std::ostream& o, const Cat& cat) {
// 	o << cat.getBrainAdress();
// 	return (o);
// };
	