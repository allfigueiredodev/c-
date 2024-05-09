/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:34:27 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/09 20:28:06 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string w_type) : _type(w_type) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) {
	return (this->_type);
}

void		Weapon::setType(std::string type) {
	this->_type = type;
}