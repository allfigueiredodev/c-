/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:20:34 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/08 20:35:20 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* horde =	zombieHorde(10, "qwerty");
	for (size_t i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
}