/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:43 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/27 20:28:40 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void) {
	DiamondTrap DiamondOne("DiamondOne");
	// std::cout << "Hit points should equal to 100: " << DiamondOne.FragTrap::getHitPoints() << std::endl;
	std::cout << "Hit points should equal to 100: " << DiamondOne.FragTrap::getHitPoints() << std::endl;
	std::cout << "Energy points should equal to 50: " << DiamondOne.getEnergyPoints() << std::endl;
	std::cout << "Attack damage should equal to 30: " << DiamondOne.getAttackDamage() << std::endl;
	DiamondOne.whoAmI();
}