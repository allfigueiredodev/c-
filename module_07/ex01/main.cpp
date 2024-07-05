/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:06:54 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 18:06:55 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

void InvalidArrayTest(void){
	int size = 10;
	int* arr = NULL;
	iter<int>(arr, size, squaring<int>);
}

void ValidIntArrayTest(void){
	int size = 10;
	int* arr = new int[size];
	for(int i = 0; i < size; i++) {
		arr[i] = i;
	}
	iter<int>(arr, size, squaring<int>);
}

void ValidFloatArrayTest(void){
	int size = 10;
	float* arr = new float[size];
	for(int i = 0; i < size; i++) {
		arr[i] = i + 0.3f;
	}
	iter<float>(arr, size, squaring<float>);
}

void ValidDoubleArrayTest(void){
	int size = 10;
	double* arr = new double[size];
	for(int i = 0; i < size; i++) {
		arr[i] = i + 0.7;
	}
	iter<double>(arr, size, squaring<double>);
}

int main(void) {
	println(CYAN << "***INVALID ARRAY TEST***")
	std::cout << std::endl;
	InvalidArrayTest();
	std::cout << std::endl;
	println(CYAN << "***VALID INT ARRAY TEST***")
	std::cout << std::endl;
 	ValidIntArrayTest();
	std::cout << std::endl;
	println(CYAN << "***VALID FLOAT ARRAY TEST***")
	std::cout << std::endl;
 	ValidFloatArrayTest();
	std::cout << std::endl;
	println(CYAN << "***VALID DOUBLE ARRAY TEST***")
	std::cout << std::endl;
 	ValidDoubleArrayTest();
}