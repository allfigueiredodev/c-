#include "real_type.h"

Base * generate(void){
	int i = rand() % 4;

	switch (i)
	{
	case 0:
		return (new A);

	case 1:
		return (new B);

	case 2:
		return (new C);
	
	default:
		return (new Base);
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p)){
		println(GREEN << "Class A pointer found!");
		return ;
	}
	else if (dynamic_cast<B*>(p)){
		println(GREEN << "Class B pointer found!");
		return;
	}
	else if (dynamic_cast<C*>(p)){
		println(GREEN << "Class C pointer found!");
		return;
	}
	else {
		errorln("This is not a derived class of Base.");
	}
}

void identify(Base& p) {
	try {
		A& derivedA = dynamic_cast<A&>(p);
		(void)derivedA;
		println(GREEN << "Class A reference found!");
		return;
	}
	catch (std::exception& e) {
		errorln("Class A Exception: " << e.what());
	}
	try {
		B& derivedB = dynamic_cast<B&>(p);
		(void)derivedB;
		println(GREEN << "Class B reference found!");
		return;
	}
	catch (std::exception& e) {
		errorln("Class B Exception: " << e.what());
	}
	try {
		C& derivedC = dynamic_cast<C&>(p);
		(void)derivedC;
		println(GREEN << "Class C reference found!");
		return;
	}
	catch (std::exception& e) {
		errorln("Class C Exception: " << e.what());
	}
	errorln("This is not a derived class of Base.");
}