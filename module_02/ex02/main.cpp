#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	std::cout << YELLOW << "***RULE TESTS***" << DFT << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << YELLOW << "***OTHER TESTS***" << DFT << std::endl;
	Fixed c(10);
	Fixed d(32);

	std::cout << MAG_YE << "_COMPARISON TESTS_" << DFT << std::endl;
	if (c < d)
		std::cout << "d is greater than c" << std::endl;
	else
		std::cout << "c is greater than d" << std::endl;
	
	if (c > d)
		std::cout << "c is greater than d" << std::endl;
	else
		std::cout << "d is greater than c" << std::endl;
	
	if (c == d)
		std::cout << "c equals d" << std::endl;
	else
		std::cout << "c is differente than d" << std::endl;
	
	if (c != d)
		std::cout << "c is differente than d" << std::endl;
	else
		std::cout << "c equals d" << std::endl;
	
	std::cout << MAG_YE << "_ARITHMETICS TESTS_" << DFT << std::endl;
	std::cout << MAGENTA << "d - c: " << d - c << DFT << std::endl;
	std::cout << MAGENTA << "d + c: " << d + c << DFT << std::endl;
	std::cout << MAGENTA << "d * c: " << d * c << DFT << std::endl;
	std::cout << MAGENTA << "d / c: " << d / c << DFT << std::endl;
	
	std::cout << MAG_YE << "_PRE/POST INCREMENT TESTS_" << DFT << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;	
	std::cout << --c << std::endl;	
	std::cout << c << std::endl;	
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;	
	std::cout << ++c << std::endl;	
	std::cout << c << std::endl;
	
	return (0);
}