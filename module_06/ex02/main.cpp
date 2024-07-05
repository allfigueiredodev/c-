/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:35:30 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 13:39:10 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_type.h"

void IdentifyReceivingPointerTest(void){
	for(int i = 0; i < 10; i++) {
		Base* test = generate();
		identify(test);
		delete test;
	}
}

void IdentifyReceivingReferenceTest(void){
	for(int i = 0; i < 10; i++) {
		Base* test = generate();
		identify(*test);
		delete test;
	}
}

int main(void){
	println(CYAN << "***POINTER TEST***")
	IdentifyReceivingPointerTest();
	std::cout << std::endl;
	println(CYAN << "***REFERENCE TEST***")
	IdentifyReceivingReferenceTest();
}