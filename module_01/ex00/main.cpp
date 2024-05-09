/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:08:44 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/08 18:47:16 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie* test = new Zombie("test");
	Zombie	test2 = Zombie("test2");
	Zombie*	test3 = newZombie("test3");
	randomChump("test4");
	test->announce();
	test2.announce();
	test3->announce();
	delete(test);
	delete(test3);
}