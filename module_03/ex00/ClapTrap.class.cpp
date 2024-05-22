/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:02 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/22 20:18:56 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrap.class.hpp"

	ClapTrap::ClapTrap(void) {};
	
	ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {};
	
	ClapTrap::~ClapTrap(void) {};
	
	ClapTrap::ClapTrap(const ClapTrap& ClapTrap) {
		*this = ClapTrap;
	};
	
	ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
		if (this != &rhs){
			this->_name = rhs._name;
			this->_hitPoints = rhs._hitPoints;
			this->_energyPoints = rhs._energyPoints;
			this->_attackDamage = rhs._attackDamage;			
		}
		return (*this);
	};	
	
	void ClapTrap::attack(const std::string& target) {
		if (_energyPoints){
			std::cout << "ClapTrap " << 
			_name << "attacks " << 
			target << ", " << "causing " << RED <<
			_attackDamage << DFT << "points of damage!" << std::endl;
		}
	};
	
	void ClapTrap::takeDamage(unsigned int amount) {
		std::cout << _name << " took " << RED << amount << DFT << " of damage." << std::endl; 
		_hitPoints = _hitPoints - amount;
		_energyPoints = _energyPoints - 1;
	};
	
	void ClapTrap::beRepaired(unsigned int amount) {
		if (_energyPoints){
			std::cout << _name << " recovered " << GREEN << amount << DFT <<" of energy." << std::endl; 
			_hitPoints = _hitPoints + amount;	
			_energyPoints = _energyPoints - 1;
		}
	};
	