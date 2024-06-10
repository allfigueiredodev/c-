/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:31 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/10 17:27:18 by aperis-p         ###   ########.fr       */
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
	std::cout << BLUE << "catA constructor:" << DFT << std::endl;
	Cat catA = Cat();
	std::cout << std::endl;
	
	std::cout << BLUE << "catB copy constructor:" << DFT << std::endl;
	Cat catB(catA);
	std::cout << std::endl;
	
	std::cout << BLUE << "catC constructor:" << DFT << std::endl;
	Cat catC;
	std::cout << std::endl;
	
	std::cout << BLUE << "catC copy assign:" << DFT << std::endl;
	catC = catA;
	std::cout << std::endl;
	
	std::cout << CYAN << "catA brain adress:" << DFT << std::endl;
	catA.printBrainAdress();
	std::cout << CYAN << "catB brain adress:" << DFT << std::endl;
	catB.printBrainAdress();
	std::cout << CYAN << "catC brain adress:" << DFT << std::endl;
	catC.printBrainAdress();
	std::cout << std::endl;
	
	
	std::cout << BLUE << "Dog basic constructor:" << DFT << std::endl;
	Dog basic;
	std::cout << std::endl;
	
	std::cout << BLUE << "Dog tmp copy assign" << DFT << std::endl;
	Dog tmp = basic;
	std::cout << std::endl;
	
	std::cout << BLUE << "Dog basic2 constructor" << DFT << std::endl;
	Dog basic2;
	std::cout << std::endl;
	
	std::cout << BLUE << "Dog tmp2 copy constructor" << DFT << std::endl;
	Dog tmp2(basic2);
	std::cout << std::endl;
	basic2.tellIdeas();
	tmp2.tellIdeas();
};

void	IdeasArrayTest(void){
	Cat cat = Cat();
	Dog dog = Dog();
	
	cat.tellIdeas();	
	dog.tellIdeas();
};

int main()
{
	std::cout << YELLOW << "***SUBJECT FIRST TEST***" << DFT << std::endl;
	std::cout << std::endl;
	SubjectFirstTest();
	std::cout << std::endl;
	std::cout << YELLOW << "***SUBJECT SECOND TEST***" << DFT << std::endl;
	std::cout << std::endl;
	SubjectSecondTest();	
	std::cout << std::endl;
	std::cout << YELLOW << "***DEEP COPY TEST***" << DFT << std::endl;
	std::cout << std::endl;
	SubjectDeepCopyTest();	
	std::cout << std::endl;
	std::cout << YELLOW << "***IDEAS ARRAY TEST***" << DFT << std::endl;
	std::cout << std::endl;
	IdeasArrayTest();
	std::cout << std::endl;
	return 0;
}