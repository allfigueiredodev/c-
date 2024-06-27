#include "scalar.h"
#include "Classes/ScalarConverter/ScalarConverter.hpp"

int main (int argc, char **argv){
	if (argc != 2) {
		errorln("Bad arguments");
		println(CYAN << "Try this way: ./convert <data to be converted>");
		return (1);
	}
	ScalarConverter::convert(argv[1]);
};