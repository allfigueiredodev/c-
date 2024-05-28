/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:43 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/27 22:08:49 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main (void) {
	ClapTrap one("One");
	one.setAttackDamage(8);
	ClapTrap two("Two");
	two.setAttackDamage(10);
	std::cout << std::endl;

	one.attack("Two");
	std::cout << std::endl;
	two.takeDamage(one.getAttackDamage());
	two.beRepaired(6);
	std::cout << std::endl;
	
	two.attack("One");
	std::cout << std::endl;
	one.takeDamage(two.getAttackDamage());
	std::cout << std::endl;
	one.attack("Two");
	std::cout << std::endl;
	two.attack("One");
	std::cout << std::endl;
	one.takeDamage(two.getAttackDamage());
	one.beRepaired(10);
	std::cout << std::endl;

	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	two.attack("One");
	std::cout << std::endl;
	two.beRepaired(10);
	std::cout << std::endl;

	std::cout << CYAN << "ClapTrap One energy points left: " << one.getEnergyPoints() << DFT << std::endl;
	std::cout << CYAN << "ClapTrap Two energy points left: " << two.getEnergyPoints() << DFT << std::endl;
	std::cout << std::endl;
}