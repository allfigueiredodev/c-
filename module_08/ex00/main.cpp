#include "easyfind.h"

void ElementNotPresentTest(void){
	std::deque<int> 	arr(10);
	int					arrIndex = 0;
	int					element = 3;

	println(ORANGE << "We are going to look for the element: " << element << ".");
	println(" ");	
	for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); it++) {
		*it = arrIndex * arrIndex;
		std::cout << GREEN << "index " << arrIndex << " : " << *it << std::endl;
		arrIndex++;
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
	std::deque<int> 	arr(10);
	int					arrIndex = 0;
	int					element = 25;

	println(ORANGE << "We are going to look for the element: " << element << ".");		
	println(" ");	
	for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); it++) {
		*it = arrIndex * arrIndex;
		std::cout << GREEN << "index " << arrIndex << " : " << *it << std::endl;
		arrIndex++;
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