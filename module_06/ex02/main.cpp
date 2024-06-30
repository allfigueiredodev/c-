#include "real_type.h"

void IdentifyReceivingPointerTest(void){
	for(int i = 0; i < 30; i++) {
		Base* test = generate();
		identify(test);
		delete test;
	}
}

void IdentifyReceivingReferenceTest(void){
	for(int i = 0; i < 30; i++) {
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