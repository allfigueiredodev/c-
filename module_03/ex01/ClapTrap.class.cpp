/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:02 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/24 21:29:08 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "ClapTrap default constructor called." << std::endl;
	};
	
	ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "ClapTrap " << name << " was created." << std::endl;
	};
	
	ClapTrap::~ClapTrap(void) {
		std::cout << "ClapTrap " << _name << " was destroyed." << std::endl;
	};
	
	ClapTrap::ClapTrap(const ClapTrap& ClapTrap) {
		std::cout << "ClapTrap copy constructor called." << std::endl;
		*this = ClapTrap;
	};
	
	ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
		std::cout << "ClapTrap assign copy operator called." << std::endl;
		if (this != &rhs){
			this->_name = rhs._name;
			this->_hitPoints = rhs._hitPoints;
			this->_energyPoints = rhs._energyPoints;
			this->_attackDamage = rhs._attackDamage;			
		}
		return (*this);
	};	
	
	void ClapTrap::attack(const std::string& target) {
		if (_energyPoints && _hitPoints) {
			std::cout << "ClapTrap " << MAG_YE <<
			_name << DFT << " attacks " << BLUE_GREEN <<
			target << DFT << ", " << "causing " << RED <<
			_attackDamage << DFT << " points of damage!" << std::endl;
		_energyPoints = _energyPoints - 1;
		std::cout << "ClapTrap " << MAG_YE << _name << DFT << " has " << 
		BLUE <<	_energyPoints << DFT << " energy points left." << std::endl;
		}
		else {
			(!_energyPoints) ? 
		std::cout << "ClapTrap " << MAG_YE <<  _name << DFT << 
		" can't attack, there is no energy points left to use." << std::endl : 
		std::cout << "ClapTrap " << MAG_YE <<  _name << DFT << RED <<
		" is dead." << DFT << std::endl;
		}
	};
	
	void ClapTrap::takeDamage(unsigned int amount) {
		if(_hitPoints > 0){
			std::cout << "ClapTrap " << BLUE_GREEN << _name << DFT << 
			" took " << RED << amount << DFT << " of damage." << std::endl; 
			_hitPoints = _hitPoints - amount;
		}
		(_hitPoints > 0 ) ? 
			std::cout << "ClapTrap " << BLUE_GREEN << _name << DFT << 
			" has " << YELLOW << _hitPoints << DFT <<
			" hit points left." << std::endl :
			std::cout << "ClapTrap " << BLUE_GREEN << _name << DFT << 
			" is already dead." << std::endl ; 
	};
	
	void ClapTrap::beRepaired(unsigned int amount) {
		if (_energyPoints && _hitPoints){
			std::cout << "ClapTrap " << BLUE_GREEN << _name << DFT << 
			" recovered " << GREEN << amount << DFT << 
			" of energy." << std::endl; 
		_hitPoints = _hitPoints + amount;
		_energyPoints = _energyPoints - 1;
		std::cout << "ClapTrap " << BLUE_GREEN <<  _name << DFT << 
		" has " << BLUE << _energyPoints << DFT <<
		" energy points left." << std::endl;
		std::cout << "ClapTrap " << BLUE_GREEN <<  _name << DFT << 
		" currently has " << YELLOW << _hitPoints << DFT <<
		" hit points." << std::endl;
		}
		else {
			(_hitPoints) ?
		std::cout << "ClapTrap " << BLUE_GREEN <<  _name << DFT << 
		" can't be repaired, there is no energy points left to use." << std::endl :
		std::cout << "ClapTrap " << BLUE_GREEN <<  _name << DFT << 
		" can't return from the dead." << std::endl;
		}
	};
	
	void ClapTrap::setAttackDamage(unsigned int amount) {
		_attackDamage = amount;
	}
	
	unsigned int ClapTrap::getAttackDamage(void) {
		return (_attackDamage);
	}
	
	unsigned int ClapTrap::getEnergyPoints(void) {
		return (_energyPoints);
	}
