/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:56:29 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/23 20:41:35 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:02 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/23 19:28:51 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.class.hpp"

	ScavTrap::ScavTrap(void) : ClapTrap() {
		std::cout << "ScavTrap default constructor called." << std::endl;
	};
	
	ScavTrap::ScavTrap(std::string name) : ClapTrap(), _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
		std::cout << "ScavTrap " << name << " was created." << std::endl;
	};
	
	ScavTrap::~ScavTrap(void) {
		std::cout << "ScavTrap " << _name << " was destroyed." << std::endl;
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
		std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
	};

