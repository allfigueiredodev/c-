/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:02 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/29 13:17:56 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

	ScavTrap::ScavTrap(void) : ClapTrap() {
		std::cout << BLUE << "ScavTrap default constructor called." << DFT << std::endl;
		this->_hitPoints = 100; 
		this->_energyPoints = 50;
		this->_attackDamage = 20;
	};
	
	ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
		std::cout << BLUE << "ScavTrap " << name << " was created." << DFT << std::endl;
		this->_hitPoints = 100; 
		this->_energyPoints = 50;
		this->_attackDamage = 20;
	};
	
	ScavTrap::~ScavTrap(void) {
		std::cout << BLUE << "ScavTrap " << _name << " was destroyed." << DFT << std::endl;
	};
	
	ScavTrap::ScavTrap(const ScavTrap& ScavTrap) {
		std::cout << "ScavTrap copy constructor called." << std::endl;
		*this = ScavTrap;
	};
	
	ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
		std::cout << "ScavTrap assign copy operator called." << std::endl;
		if (this != &rhs){
			this->_name = rhs._name;
			this->_hitPoints = rhs._hitPoints;
			this->_energyPoints = rhs._energyPoints;
			this->_attackDamage = rhs._attackDamage;			
		}
		return (*this);
	};
	
	void ScavTrap::guardGate() {
		std::cout << CYAN << "ScavTrap" << _name << " is now in Gate keeper mode." << DFT <<  std::endl;
	};

	void ScavTrap::attack(const std::string& target) {
		if (_energyPoints && _hitPoints) {
			std::cout << "ScavTrap " << MAG_YE <<
			_name << DFT << " attacks " << BLUE_GREEN <<
			target << DFT << ", " << "causing " << RED <<
			_attackDamage << DFT << " points of damage!" << std::endl;
		_energyPoints = _energyPoints - 1;
		std::cout << "ScavTrap " << MAG_YE << _name << DFT << " has " << 
		BLUE <<	_energyPoints << DFT << " energy points left." << std::endl;
		}
		else {
			(!_energyPoints) ? 
		std::cout << "ScavTrap " << MAG_YE <<  _name << DFT << 
		" can't attack, there is no energy points left to use." << std::endl : 
		std::cout << "ScavTrap " << MAG_YE <<  _name << DFT << RED <<
		" is dead." << DFT << std::endl;
		}	
	}

	std::string ScavTrap::getName(void) {
		return (_name);
	}
	
	int ScavTrap::getHitPoints(void) {
		return (_hitPoints);
	}
