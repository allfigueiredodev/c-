/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:43 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/29 13:10:31 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void) {
	FragTrap Frag_XYZ("Frag_XYZ");
	FragTrap Frag_QWERTY("Frag_QWERTY");
	std::cout << std::endl;

	Frag_XYZ.attack("Frag_XYZ");
	std::cout << std::endl;

	Frag_QWERTY.takeDamage(Frag_XYZ.getAttackDamage());
	std::cout << std::endl;

	std::cout << "Frag_XYZ name: " << CYAN << Frag_XYZ.getName() << DFT << std::endl;
	std::cout << "Frag_XYZ damage: " << CYAN << Frag_XYZ.getAttackDamage() << DFT << std::endl;
	std::cout << "Frag_XYZ energy: " << CYAN << Frag_XYZ.getEnergyPoints() << DFT << std::endl;
	std::cout << "Frag_XYZ hit points: " << CYAN << Frag_XYZ.getHitPoints() << DFT << std::endl;
	std::cout << std::endl;

	std::cout << "Frag_QWERTY name: " << CYAN << Frag_QWERTY.getName() << DFT << std::endl;
	std::cout << "Frag_QWERTY damage: " << CYAN << Frag_QWERTY.getAttackDamage() << DFT << std::endl;
	std::cout << "Frag_QWERTY energy: " << CYAN << Frag_QWERTY.getEnergyPoints() << DFT << std::endl;
	std::cout << "Frag_QWERTY hit points: " << CYAN << Frag_QWERTY.getHitPoints() << DFT << std::endl;
	std::cout << std::endl;

	Frag_XYZ.highFivesGuys();
	Frag_QWERTY.highFivesGuys();
	std::cout << std::endl;
}