#include "MutantStack.h"
#include "Classes/MutantStack/MutantStack.hpp"

void	DefaultStackMethodsTest(void) {
	MutantStack<int> test;

	println(ORANGE << "Size before push: " << test.size());
	println(GREEN << "Pushing some elements...");
	test.push(42);	
	test.push(21);	
	test.push(1337);	
	println(ORANGE << "Size after push: " << test.size());
	println(ORANGE << "Last element: " << test.top());
	println(GREEN << "Popping last element...");
	test.pop();
	println(ORANGE << "Current last element: " << test.top());
};

void	IteratorsTest(void) {
	MutantStack<int> test;

	test.push(42);	
	test.push(21);	
	test.push(1337);	
	println(GREEN << "First element: " << *test.begin());
	println(GREEN << "Last element: " << *(--test.end()));
};

void	ReverseIteratorsTest(void) {
	MutantStack<int> test;

	test.push(42);	
	test.push(21);	
	test.push(1337);	
	println(GREEN << "First element: " << *test.rbegin());
	println(GREEN << "Last element: " << *(--test.rend()));
}; 

void	ConstIteratorsTest(void) {
	MutantStack<int> test;

	test.push(42);	
	test.push(21);	
	test.push(1337);
	MutantStack<int>::const_iterator bIt = test.begin();
	MutantStack<int>::const_iterator eIt = test.end();
	(void)bIt; // just to be able to compile
	(void)eIt; // just to be able to compile
	// *bIt = 66;
	// *eIt = 99;
};

void	ConstReverseIteratorsTest(void) {
	MutantStack<int> test;

	test.push(42);	
	test.push(21);	
	test.push(1337);
	MutantStack<int>::const_reverse_iterator bIt = test.rbegin();
	MutantStack<int>::const_reverse_iterator eIt = test.rend();
	(void)bIt; // just to be able to compile
	(void)eIt; // just to be able to compile
	// *bIt = 66;
	// *eIt = 99;
}; 

int main()
{
	println(CYAN << "***TESTS***");
	println(" ");
	println(CYAN << "***DEFAULT STACK METHODS TEST***");
	DefaultStackMethodsTest();
	println(" ");
	println(CYAN << "***ITERATORS TEST***");	
	println(" ");
	IteratorsTest();
	println(" ");
	println(CYAN << "***REVERSE ITERATORS TEST***");	
	println(" ");
	ReverseIteratorsTest();
	println(" ");
	println(CYAN << "***CONST ITERATORS TEST***");	
	println(" ");
	ConstIteratorsTest();
	println(YELLOW << "Try uncomment the assignment.");
	println(" ");
	println(CYAN << "***CONST REVERSE ITERATORS TEST***");	
	println(" ");
	ConstReverseIteratorsTest();
	println(YELLOW << "Try uncomment the assignment.");
	println(" ");
	return (0);
}