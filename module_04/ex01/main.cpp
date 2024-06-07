/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:31 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/07 11:12:20 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

// int		SubjectFirstTest(void){
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	return 0;
// }

// void	SubjectSecondTest(void){
// 	Animal* Animals[20];
// 	for (int i = 0; i < 20; ++i){
// 		if (i < 10)
// 			Animals[i] = new Cat();
// 		else
// 			Animals[i] = new Dog();
// 	}
// 	for (int i = 0; i < 20; ++i)
// 		delete Animals[i];
// }
	
void	SubjectDeepCopyTest(){
	Cat catA = Cat();
	// Cat* catB(catA);
	Cat catC;
	catC = catA;
	Cat catD(catA);
	// Cat* catD = new Cat();
	// std::cout << "catA adress: " << catA << std::endl;
	// std::cout << "catB adress: " << catB << std::endl;
	// std::cout << "catC adress: " << catC << std::endl;
	// std::cout << "catD adress: " << catD << std::endl;
	catA.printBrainAdress();
	// catB->printBrainAdress();
	catC.printBrainAdress();
	// catD->printBrainAdress();
	catD.printBrainAdress();
}

int main()
{
	// SubjectFirstTest();
	// SubjectSecondTest();	
	SubjectDeepCopyTest();	
	return 0;
}