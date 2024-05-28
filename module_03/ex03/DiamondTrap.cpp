/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:02 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/27 20:05:05 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

	DiamondTrap::DiamondTrap(void) {
		std::cout << GREEN << "DiamondTrap default constructor called." << DFT << std::endl;
	};
	
	DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
		std::cout << GREEN << "DiamondTrap " << name << " was created." << DFT << std::endl;
		this->name = name;
		ScavTrap::_energyPoints = 50;
		this->_energyPoints = ScavTrap::_energyPoints;
	};
	
	DiamondTrap::~DiamondTrap(void) {
		std::cout << "DiamondTrap " << name << " was destroyed." << std::endl;
	};
	
	DiamondTrap::DiamondTrap(const DiamondTrap& DiamondTrap) {
		std::cout << "DiamondTrap copy constructor called." << std::endl;
		*this = DiamondTrap;
	};
	
	DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
		std::cout << "DiamondTrap assign copy operator called." << std::endl;
		if (this != &rhs){
			this->_name = rhs._name;
			this->_hitPoints = rhs._hitPoints;
			this->_energyPoints = rhs._energyPoints;
			this->_attackDamage = rhs._attackDamage;			
		}
		return (*this);
	};

	void DiamondTrap::attack(const std::string& target) {
		ScavTrap::attack(target);
	}

	void DiamondTrap::whoAmI(void) {
		std::cout << "My Diamond name is: " << name << std::endl;
		std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
	}

	// std::string DiamondTrap::getName(void) {
	// 	return (name);
	// }
	
	// int DiamondTrap::getHitPoints(void) {
	// 	return (_hitPoints);
	// }
