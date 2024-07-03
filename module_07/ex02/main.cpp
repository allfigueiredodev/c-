#include "array.h"
#include "Classes/Array/Array.hpp"

void	DefaultConstructorTest(void) {
	Array<int> intArr;
	// println(MAGENTA << "My adress: " << intArr);
	println(BLUE << intArr.size());
	intArr.addBack(42);
	// intArr[0] = 42;
	std::cout << GREEN << intArr.getIndex(0) << DFT << std::endl;
	println(BLUE << intArr.size());
	intArr.addBack(433);
	std::cout << GREEN << intArr.getIndex(1) << DFT << std::endl;
	println(BLUE << intArr.size());
	// Array<float> floatArr;
	// // println(MAGENTA << "My adress: " << floatArr);
	// floatArr[0] = 42.42f;
	// std::cout << GREEN << floatArr.getIndex(0) << DFT << std::endl;
	// Array<double> doubleArr;
	// // println(MAGENTA << "My adress: " << doubleArr);
	// doubleArr[0] = 24.24;
	// std::cout << GREEN << doubleArr.getIndex(0) << DFT << std::endl;
	// Array<std::string> stringArr;
	// // println(MAGENTA << "My adress: " << stringArr);
	// stringArr[0] = "forty two"; 
	// std::cout << GREEN << stringArr.getIndex(0) << DFT << std::endl;
};

// void	ParameterizedConstructorTest(void) {

// };

// void	DeepCopyConstructorAndAssignmentTest(void) {

// };

// void	SubscriptionOperatorTest(void) {

// };

// void	ArrayBoundariesExceptionTest(void) {

// };

// void	SizeMethodTest(void) {

// };

int main(void)
{
	printlnnl(CYAN << "***DEFAULT CONSTRUCTOR TEST***");
	DefaultConstructorTest();
	println("\n");
	// printlnnl(CYAN << ***PARAMETERIZED CONSTRUCTOR TEST***);
	// ParameterizedConstructorTest();
	// println("\n");
	// printlnnl(CYAN << ***DEEP COPY CONSTRUCTOR AND ASSIGMENT TEST***);
	// DeepCopyConstructorAndAssignmentTest();
	// println("\n");
	// printlnnl(CYAN << ***SUBSCRIPTION OPERATOR TEST***);
	// SubscriptionOperatorTest();
	// println("\n");
	// printlnnl(CYAN << ***ARRAY BOUNDARIES EXCEPTION TEST***);
	// ArrayBoundariesExceptionTest();
	// println("\n");
	// printlnnl(CYAN << ***SIZE METHOD TEST***);
	// SizeMethodTest();
}