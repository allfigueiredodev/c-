/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:43 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/23 17:57:45 by aperis-p         ###   ########.fr       */
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
	
}