#include "easyfind.h"

void ElementNotPresentTest(void){
	std::vector<int> 	arr(10);
	int					element = 3;

	println(ORANGE << "We are going to look for the element: " << element << ".");
	println(" ");	
	for (unsigned long i = 0; i < arr.size(); i++) {
		arr[i] = i * i;
		std::cout << GREEN << "index " << i << " : " << arr[i] << std::endl;
	}
	println(" ");	
	try {
		easyfind(arr, element);
	}
	catch (std::exception& e) {
		errorln(e.what() << element << " is not present in this array.");
	}
}

void ElementPresentTest(void){
	std::vector<int> 	arr(10);
	int					element = 25;

	println(ORANGE << "We are going to look for the element: " << element << ".");		
	println(" ");	
	for (unsigned long i = 0; i < arr.size(); i++) {
		arr[i] = i * i;
		std::cout << GREEN << "index " << i << " : " << arr[i] << std::endl;
	}
	println(" ");	
	try {
		easyfind(arr, element);
	}
	catch (std::exception& e) {
		errorln(e.what() << element << " is not present in this array.");
	}
}

int main(void)
{
	println(CYAN << "***ELEMENT NOT PRESENT TEST***");
	println(" ");
	ElementNotPresentTest();
	println(" ");
	println(CYAN << "***ELEMENT PRESENT TEST***");
	println(" ");
	ElementPresentTest();
	println(" ");
}