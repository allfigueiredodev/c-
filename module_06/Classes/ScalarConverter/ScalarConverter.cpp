#include "scalar.h"
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
    std::cout << "ScalarConverter class default constructor called." << std::endl;
};

ScalarConverter::ScalarConverter(const ScalarConverter& ScalarConverter) {
    std::cout << "ScalarConverter class copy constructor called." << std::endl;
    *this = ScalarConverter;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    std::cout << "ScalarConverter class copy assign operator called." << std::endl;
    if (this != &rhs){
        //...
    }
    return *this;
};

ScalarConverter::~ScalarConverter(void) {
    std::cout << "ScalarConverter class destructor called." << std::endl;
};

ScalarConverter::convert(std::string value){
    // • char
    // • int
    // • float
    // • double
};
