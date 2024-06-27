#include "scalar.h"
#include "Classes/ScalarConverter/ScalarConverter.hpp"

int main (int argc, char **argv){
	if (argc != 2) {
		errorln("Bad arguments");
		println(CYAN << "Try this way: ./convert <data to be converted>");
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	println(CYAN << "***TEST***" << DFT);
	println(BLUE << "Int min: " << INT_MIN << DFT);
	println(BLUE << "Int max: " << INT_MAX << DFT);
	std::cout << std::fixed;
	std::cout.precision(20);
	println(BLUE << "Float min: " << FLT_MIN << DFT);
	println(BLUE << "Float max: " << FLT_MAX << DFT);
	println(BLUE << "Double min: " << DBL_MIN << DFT);
	println(BLUE << "Double max: " << DBL_MAX << DFT);
	println(BLUE << "Long min: " << LONG_MIN << DFT);
	println(BLUE << "Long max: " << LONG_MAX << DFT);
	// println(BLUE << "Long long min: " << LONG_LONG_MIN << DFT);
	// println(BLUE << "Long long max: " << LONG_LONG_MAX << DFT);
	// int i = 0;
	// i = atoi("76576575765757656757657576");
	// println(ORANGE << "Atoi return: " << i);
};