/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:43 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/25 23:14:51 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void) {
	ClapTrap one("One");
	one.setAttackDamage(8);
	ClapTrap two("Two");
	two.setAttackDamage(10);

	one.attack("Two");
	two.takeDamage(one.getAttackDamage());
	two.beRepaired(6);
	
	two.attack("One");
	one.takeDamage(two.getAttackDamage());
	one.attack("Two");
	two.attack("One");
	one.takeDamage(two.getAttackDamage());
	one.beRepaired(10);

	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.beRepaired(10);

	std::cout << "One: " << one.getEnergyPoints() << std::endl;
	std::cout << "Two: " << two.getEnergyPoints() << std::endl;

	ScavTrap Scav_one("Scav_one");
	ScavTrap Scav_two("Scav_two");	
	Scav_one.attack("Scav_two");
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	Scav_one.attack("Scav_two");
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	Scav_one.attack("Scav_two");
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	Scav_one.attack("Scav_two");
	Scav_two.takeDamage(Scav_one.getAttackDamage());
	Scav_two.beRepaired(50);

	std::cout << "Scav_one name: " << CYAN << Scav_one.getName() << DFT << std::endl;
	std::cout << "Scav_one damage: " << CYAN << Scav_one.getAttackDamage() << DFT << std::endl;
	std::cout << "Scav_one energy: " << CYAN << Scav_one.getEnergyPoints() << DFT << std::endl;
	std::cout << "Scav_one hit points: " << CYAN << Scav_one.getHitPoints() << DFT << std::endl;
	std::cout << "Scav_two name: " << CYAN << Scav_two.getName() << DFT << std::endl;
	std::cout << "Scav_two damage: " << CYAN << Scav_two.getAttackDamage() << DFT << std::endl;
	std::cout << "Scav_two energy: " << CYAN << Scav_two.getEnergyPoints() << DFT << std::endl;
	std::cout << "Scav_two hit points: " << CYAN << Scav_two.getHitPoints() << DFT << std::endl;
	Scav_one.guardGate();
	Scav_two.guardGate();

	FragTrap Frag_XYZ("Frag_XYZ");
	FragTrap Frag_QWERTY("Frag_QWERTY");
	std::cout << std::endl;
	Frag_XYZ.attack("Frag_XYZ");
	Frag_QWERTY.takeDamage(Frag_XYZ.getAttackDamage());

	Frag_XYZ.highFivesGuys();
	Frag_QWERTY.highFivesGuys();
}