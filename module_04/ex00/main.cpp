/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:31 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/05 21:54:48 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

void AnimalSoundTest(void) {
	const Animal* meta = new Animal();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	delete meta;
};

void DogSoundTest(void) {
	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	delete j;
};

void CatSoundTest(void) {
	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	delete i;
};

void WrongAnimalWrongCatTest(void) {
	const WrongAnimal* x = new WrongCat();
	std::cout << x->getType() << " " << std::endl;
	x->makeSound();
	delete x;
};

int main() {
	std::cout << CYAN << "*ANIMAL CLASS TEST*" << DFT << std::endl;
	AnimalSoundTest();
	std::cout << std::endl;
	std::cout << CYAN << "*DOG CLASS TEST*" << DFT << std::endl;
	DogSoundTest();
	std::cout << std::endl;
	std::cout << CYAN << "*CAT CLASS TEST*" << DFT << std::endl;
	CatSoundTest();
	std::cout << std::endl;
	std::cout << CYAN << "*WRONG CLASS TEST*" << DFT << std::endl;
	WrongAnimalWrongCatTest();
	return 0;
};
