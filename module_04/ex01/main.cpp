/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:31 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/31 00:35:52 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int main()
{

	// Animal* Animals[20];
	// for (int i = 0; i < 20; ++i){
	// 	if (i < 10)
	// 		Animals[i] = new Cat();
	// 	else
	// 		Animals[i] = new Dog();
	// }

	// for (int i = 0; i < 20; ++i)
	// 	delete Animals[i];
	Animal* AnimalX = new Cat();
	delete AnimalX;
	
	return 0;
}