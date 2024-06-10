/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:59:06 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/10 17:45:10 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"
#include <cstdio>

Brain::Brain(void){
	std::cout << "Brain class default constructor called." << std::endl;
};

Brain::Brain(const Brain& Brain){
	std::cout << "Brain class copy constructor called." << std::endl;
	*this = Brain;
};

Brain& Brain::operator=(const Brain& rhs){
	std::cout << "Brain class copy assign operator called." << std::endl;
	if (this != &rhs){
		for (int i = 0; i < 100; i++){
			_ideas[i] = rhs._ideas[i];	
		}
	}
	return (*this);
};

Brain::~Brain(void){
	std::cout << "Brain class destructor called." << std::endl;
};

std::string Brain::getIdeas(int i) {
	return (this->_ideas[i]);
};


void Brain::setIdeas(std::string idea, int i){
	this->_ideas[i] = idea;
	char buffer[5];
	sprintf(buffer, "%d", i);
	this->_ideas[i] += buffer;
};
