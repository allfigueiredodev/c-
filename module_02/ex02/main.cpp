#include <iostream>
#include "Fixed.hpp"

void ComparisonOperatorGreaterThanTest(const Fixed&  a, const Fixed&  b){
	std::cout << "Is c greater than d? ";
	(a > b) ? std::cout << GREEN << "True" << DFT << std::endl
	: std::cout << RED << "False" << DFT << std::endl;
};

void ComparisonOperatorLessThanTest(const Fixed&  a, const Fixed&  b){
	std::cout << "Is c less than d? ";
	(a < b)	? std::cout << GREEN << "True" << DFT << std::endl
	: std::cout << RED << "False" << DFT << std::endl;
};

void ComparisonOperatorGreaterOrEqualToTest(const Fixed&  a, const Fixed&  b){
	std::cout << "Is c greater or equal to d? ";
	(a >= b) ? std::cout << GREEN << "True" << DFT << std::endl
	: std::cout << RED << "False" << DFT << std::endl;
};

void ComparisonOperatorLessOrEqualToTest(const Fixed&  a, const Fixed&  b){
	std::cout << "Is c less or equal to d? ";
	(a <= b) ? std::cout << GREEN << "True" << DFT << std::endl
	: std::cout << RED << "False" << DFT << std::endl;
};

void ComparisonOperatorEqualToTest(const Fixed&  a, const Fixed&  b){
	std::cout << "Is c equal to d? ";
	(a == b) ? std::cout << GREEN << "True" << DFT << std::endl
	: std::cout << RED << "False" << DFT << std::endl;
};

void ComparisonOperatorDifferentFromTest(const Fixed&  a, const Fixed&  b){
	std::cout << "Is d different from c? ";
	(a != b) ? std::cout << GREEN << "True" << DFT << std::endl
	: std::cout << RED << "False" << DFT << std::endl;
};

void StaticMinMaxFunctionsTest(Fixed& a, Fixed& b) {
	std::cout << CYAN << "Min is: " << Fixed::min(a, b) << std::endl;
	std::cout << CYAN << "Max is: " << Fixed::max(a, b) << std::endl;
};

void StaticConstMinMaxFunctionsTest(const Fixed& a, const Fixed& b) {
	std::cout << CYAN << "Min is: " << Fixed::min(a, b) << std::endl;
	std::cout << CYAN << "Max is: " << Fixed::max(a, b) << std::endl;
};

int main( void ) {

	std::cout << YELLOW << "***SUBJECT TESTS***" << DFT << std::endl;
	std::cout << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "***OTHER TESTS***" << DFT << std::endl;
	Fixed c(32);
	Fixed d(10);
	std::cout << GREEN << "c: " << c << DFT << std::endl;
	std::cout << GREEN << "d: " << d << DFT << std::endl;
	std::cout << std::endl;

	std::cout << MAG_YE << "_COMPARISON TESTS_" << DFT << std::endl;
	std::cout << std::endl;
	ComparisonOperatorGreaterThanTest(c, d);
	ComparisonOperatorLessThanTest(c, d);

	d.setIntRawBits(32);
	std::cout << CYAN << "d is now worth: " << d.toFloat() << DFT << std::endl;

	ComparisonOperatorGreaterOrEqualToTest(c, d);
	ComparisonOperatorLessOrEqualToTest(c, d);

	d.setIntRawBits(33);
	std::cout << CYAN << "d is now worth: " << d.toFloat() << DFT << std::endl;

	ComparisonOperatorEqualToTest(c, d);
	ComparisonOperatorDifferentFromTest(c, d);
	std::cout << std::endl;

	std::cout << MAG_YE << "_ARITHMETICS TESTS_" << DFT << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA << "d - c: " << d - c << DFT << std::endl;
	std::cout << MAGENTA << "d + c: " << d + c << DFT << std::endl;
	std::cout << MAGENTA << "d * c: " << d * c << DFT << std::endl;
	std::cout << MAGENTA << "d / c: " << d / c << DFT << std::endl;
	std::cout << std::endl;

	std::cout << MAG_YE << "_PRE/POST INCREMENT TESTS_" << DFT << std::endl;
	std::cout << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;	
	std::cout << --c << std::endl;	
	std::cout << c << std::endl;	
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;	
	std::cout << ++c << std::endl;	
	std::cout << c << std::endl;
	std::cout << std::endl;

	std::cout << MAG_YE << "_MIN/MAX STATIC FUNCTIONS TESTS_" << DFT << std::endl;
	std::cout << std::endl;
	Fixed min(20);
	Fixed max(42);
	const Fixed cMin(30);
	const Fixed cMax(52);
	StaticMinMaxFunctionsTest(min, max);
	std::cout << std::endl;
	StaticConstMinMaxFunctionsTest(cMin, cMax);
	
	return (0);
}