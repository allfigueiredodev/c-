/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:34:17 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/09 20:50:36 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL) {}

HumanB::~HumanB(void){}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack(void) {
	if(!_weapon)
		std::cout << _name << " attacks with their ... DAMMIT GOT NO WEAPON!!!! /o\\ *proceeds to run away as fast as a thief*" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}