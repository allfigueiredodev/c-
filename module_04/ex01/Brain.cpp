/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:59:06 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/29 20:32:36 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"
#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain class default constructor called." << std::endl;
};

Brain::Brain(const Brain& Brain){
	std::cout << "Brain class copy constructor called." << std::endl;
};

Brain& Brain::operator=(const Brain& Brain){
	std::cout << "Brain class copy assign operator called." << std::endl;
};

Brain::~Brain(void){
	std::cout << "Brain class destructor called." << std::endl;
};
