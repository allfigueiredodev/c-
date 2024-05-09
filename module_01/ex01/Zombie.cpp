/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:35:27 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/08 20:38:31 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->_name << " was destroyed!" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(std::string name){
	this->_name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N]; 
	for (int i = 0; i < N; i++)
		horde[i].setZombieName(name);
	return (horde);
}
