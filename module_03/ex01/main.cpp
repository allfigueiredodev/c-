/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:43 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/29 13:12:16 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void) {
	ScavTrap Scav_one("Scav_one");
	ScavTrap Scav_two("Scav_two");	
	
	Scav_one.attack("Scav_two");
	std::cout << std::endl;
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	std::cout << std::endl;
	
	Scav_one.attack("Scav_two");
	std::cout << std::endl;
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	std::cout << std::endl;
	
	Scav_one.attack("Scav_two");
	std::cout << std::endl;
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	std::cout << std::endl;
	
	Scav_one.attack("Scav_two");
	std::cout << std::endl;
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	std::cout << std::endl;
	
	Scav_two.beRepaired(50);
	std::cout << std::endl;

	std::cout << "Scav_one name: " << CYAN << Scav_one.getName() << DFT << std::endl;
	std::cout << "Scav_one damage: " << CYAN << Scav_one.getAttackDamage() << DFT << std::endl;
	std::cout << "Scav_one energy: " << CYAN << Scav_one.getEnergyPoints() << DFT << std::endl;
	std::cout << "Scav_one hit points: " << CYAN << Scav_one.getHitPoints() << DFT << std::endl;
	std::cout << std::endl;
	
	std::cout << "Scav_two name: " << CYAN << Scav_two.getName() << DFT << std::endl;
	std::cout << "Scav_two damage: " << CYAN << Scav_two.getAttackDamage() << DFT << std::endl;
	std::cout << "Scav_two energy: " << CYAN << Scav_two.getEnergyPoints() << DFT << std::endl;
	std::cout << "Scav_two hit points: " << CYAN << Scav_two.getHitPoints() << DFT << std::endl;
	std::cout << std::endl;
	
	Scav_one.guardGate();
	Scav_two.guardGate();
	std::cout << std::endl;
}