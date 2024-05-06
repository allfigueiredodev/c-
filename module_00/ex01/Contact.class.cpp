/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:44 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/06 09:54:56 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"

Contact::Contact(void){
	std::cout << "Constructor called" << std::endl;
	return ;
};

Contact::~Contact(void){
	std::cout << "Destructor called" << std::endl;
	return ;
};

std::string Contact::getIndex(void) const{
	return (this->_index);
}
void Contact::setIndex(int i){
	this->_index = i;
}

