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

void ScalarConverter::convert(std::string value) {
    int i = -1;

    while (i != -1 && i < TOTAL_TYPES) {
        i = 
    }

    // • isChar
    // • isInt
    // • isFloat
    // • isDouble
};

int ScalarConverter::isChar(std::string value){

};

int ScalarConverter::isInt(std::string value){

};

int ScalarConverter::isFloat(std::string value){

};

int ScalarConverter::isDouble(std::string value){

};