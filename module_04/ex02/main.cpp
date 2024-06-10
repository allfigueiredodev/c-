/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:31 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/10 17:57:29 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int main()
{
	// AAnimal Animal;
	AAnimal* Animals[20];
	for (int i = 1; i <= 20; i++){
		if (i - 1 < 10) {
			Animals[i - 1] = new Cat();
			std::cout << YELLOW <<"Cat nº: " << i << " created." << DFT << std::endl;
		}
		else {
			Animals[i - 1] = new Dog();
			std::cout << MAGENTA << "Dog nº: " << i << " created." << DFT << std::endl;
		}
	}

	for (int i = 1; i <= 20; i++)
	{
		delete Animals[i - 1];
		std::cout << RED << "Animal nº: " << i << " destroyed." << DFT << std::endl;
	}
	AAnimal* AnimalX = new Cat();
	delete AnimalX;
	
	return 0;
}