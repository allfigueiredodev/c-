/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:06:06 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 18:06:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "Classes/Array/Array.hpp"

void	DefaultConstructorTest(void) {
	Array<int> intArr;
	intArr.addBack(42);
	println(GREEN << "Passing <int>: " << BLUE << intArr.getIndex(0));
	Array<float> floatArr;
	floatArr.addBack(42.42f);
	println(GREEN << "Passing <float>: " << BLUE << floatArr.getIndex(0));
	Array<double> doubleArr;
	doubleArr.addBack(42.42f);
	println(GREEN << "Passing <double>: " << BLUE << doubleArr.getIndex(0));
	Array<std::string> stringArr;
	stringArr.addBack("Fourty Two");
	println(GREEN << "Passing <string>: " << BLUE << stringArr.getIndex(0));
};

void	ParameterizedConstructorTest(void) {
	Array<int> intArr(3);
	intArr[0] = 1;
	intArr[1] = 2;
	intArr[2] = 3;
	println(GREEN << "int array: " << BLUE << intArr[0] << ", " << intArr[1] << ", " << intArr[2]);
	Array<std::string> stringArr(3);
	stringArr[0] = "qwerty";
	stringArr[1] = "asdfgh";
	stringArr[2] = "zxcvbn";
	println(GREEN << "int array: " << BLUE << stringArr[0] << ", " << stringArr[1] << ", " << stringArr[2]);
};

void	DeepCopyConstructorAndAssignmentTest(void) {
	Array<int>	intArr;
	Array<int>	intArrCpy;
	intArrCpy = intArr;
	println(GREEN << "intArr adress: " << BLUE << &intArr.getIndex(0));
	println(GREEN << "intArrCpy adress: " << BLUE << &intArrCpy.getIndex(0));
};

void	ArrayBoundariesExceptionTest(void) {
	Array<int> intArr(3);
	try {
		intArr[5] = 10;
	}
	catch (const std::out_of_range& e) {
		errorln(e.what());
	}
};

void	SizeMethodTest(void) {
	Array<int> intArr(200);
	println(GREEN << "intArr size: " << BLUE << intArr.size());
};

int main(void)
{
	printlnnl(CYAN << "***DEFAULT CONSTRUCTOR TEST***");
	DefaultConstructorTest();
	println("\n");
	printlnnl(CYAN << "***PARAMETERIZED CONSTRUCTOR TEST***");
	ParameterizedConstructorTest();
	println("\n");
	printlnnl(CYAN << "***DEEP COPY CONSTRUCTOR AND ASSIGMENT TEST***");
	DeepCopyConstructorAndAssignmentTest();
	println("\n");
	printlnnl(CYAN << "***ARRAY BOUNDARIES EXCEPTION TEST***");
	ArrayBoundariesExceptionTest();
	println("\n");
	printlnnl(CYAN << "***SIZE METHOD TEST***");
	SizeMethodTest();
}