/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:59:06 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/30 21:41:00 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

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
