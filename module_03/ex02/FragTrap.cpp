/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:02 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/25 23:04:34 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

	FragTrap::FragTrap(void) : ClapTrap() {
		std::cout << GREEN << "FragTrap default constructor called." << DFT << std::endl;
		_hitPoints = 100; 
		_energyPoints = 100;
		_attackDamage = 30;
	};
	
	FragTrap::FragTrap(std::string name) : ClapTrap(name) {
		std::cout << GREEN << "FragTrap " << name << " was created." << DFT << std::endl;
		_hitPoints = 100; 
		_energyPoints = 100;
		_attackDamage = 30;
	};
	
	FragTrap::~FragTrap(void) {
		std::cout << "FragTrap " << _name << " was destroyed." << std::endl;
	};
	
	FragTrap::FragTrap(const FragTrap& FragTrap) {
		std::cout << "FragTrap copy constructor called." << std::endl;
		*this = FragTrap;
	};
	
	FragTrap& FragTrap::operator=(const FragTrap& rhs) {
		std::cout << "FragTrap assign copy operator called." << std::endl;
		if (this != &rhs){
			this->_name = rhs._name;
			this->_hitPoints = rhs._hitPoints;
			this->_energyPoints = rhs._energyPoints;
			this->_attackDamage = rhs._attackDamage;			
		}
		return (*this);
	};
	
	void FragTrap::highFivesGuys(void) {
		std::cout << CYAN << "FragTrap " << _name <<  " says: HIGH FIIIIIIIVE!!!" << DFT <<  std::endl;
	};

	std::string FragTrap::getName(void) {
		return (_name);
	}
	
	int FragTrap::getHitPoints(void) {
		return (_hitPoints);
	}
