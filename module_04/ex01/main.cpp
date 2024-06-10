/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:31 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/08 01:43:11 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int		SubjectFirstTest(void){
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return 0;
}

void	SubjectSecondTest(void){
	Animal* Animals[20];
	for (int i = 0; i < 20; ++i){
		if (i < 10)
			Animals[i] = new Cat();
		else
			Animals[i] = new Dog();
	}
	for (int i = 0; i < 20; ++i)
		delete Animals[i];
}
	
void	SubjectDeepCopyTest(void){
	Cat catA = Cat();
	Cat catB(catA);
	Cat catC;
	catC = catA;
	catA.printBrainAdress();
	catB.printBrainAdress();
	catC.printBrainAdress();
};

void	IdeasArrayTest(void){
	Cat cat = Cat();
	Dog dog = Dog();
	
	cat.tellIdeas();	
	dog.tellIdeas();	
};

int main()
{
	SubjectFirstTest();
	SubjectSecondTest();	
	SubjectDeepCopyTest();	
	IdeasArrayTest();
	return 0;
}