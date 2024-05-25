/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:43 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/24 21:30:12 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

	// ScavTrap Scav_one("Scav_one");
	// ScavTrap Scav_two("Scav_two");	
	ScavTrap Scav_one("Scav_one");
	ScavTrap Scav_two("Scav_two");	

	std::cout << "Scav_one name: " << CYAN << Scav_one.getName() << DFT << std::endl;
	std::cout << "Scav_one damage: " << CYAN << Scav_one.getAttackDamage() << DFT << std::endl;
	std::cout << "Scav_one energy: " << CYAN << Scav_one.getEnergyPoints() << DFT << std::endl;
	std::cout << "Scav_two name: " << CYAN << Scav_two.getName() << DFT << std::endl;
	std::cout << "Scav_two damage: " << CYAN << Scav_two.getAttackDamage() << DFT << std::endl;
	std::cout << "Scav_two energy: " << CYAN << Scav_two.getEnergyPoints() << DFT << std::endl;

}