#include "scalar.h"
#include "Classes/ScalarConverter/ScalarConverter.hpp"

int main (int argc, char **argv){
	if (argc != 2) {
		errorln("Bad arguments");
		println(CYAN << "Try this way: ./convert <data to be converted>");
		return (1);
	}
	try {
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception& e)
	{
		errorln(e.what());
	}
	println(CYAN << "***TEST***" << DFT);
	// println(BLUE << "Int min: " << std::numeric_limits<int>::min() << DFT);
	// println(BLUE << "Int max: " << std::numeric_limits<int>::max() << DFT);
	// std::cout << std::fixed;
	// std::cout.precision(20);
	// println(BLUE << "Float min: " << std::numeric_limits<float>::lowest() << DFT);
	// println(BLUE << "Float max: " << std::numeric_limits<float>::max() << DFT);
	// println(BLUE << "Double min: " << std::numeric_limits<double>::lowest() << DFT);
	// println(BLUE << "Double max: " << std::numeric_limits<double>::max() << DFT);
	// println(BLUE << "Long min: " << std::numeric_limits<long>::lowest() << DFT);
	// println(BLUE << "Long max: " << std::numeric_limits<long>::max() << DFT);
	// println(BLUE << "Long long min: " << std::numeric_limits<long long>::lowest() << DFT);
	// println(BLUE << "Long long max: " << std::numeric_limits<long long>::max() << DFT);
	int i = 0;
	i = atoi("76576575765757656757657576");
	println(ORANGE << "Atoi return: " << i);
};