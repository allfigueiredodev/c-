#include "scalar.h"
#include "ScalarConverter.hpp"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ostream>
#include <sstream>
#include "Classes/ScalarConverter/ScalarConverter.hpp"

int ScalarConverter::_precision = 0;

// Define _matchFunctions here
ScalarConverter::t_matchFunctions ScalarConverter::_matchFunctions[6] = {
    { &ScalarConverter::isChar, &ScalarConverter::printIfChar },
    { &ScalarConverter::isInt, &ScalarConverter::printIfInt },
    { &ScalarConverter::isFloat, &ScalarConverter::printIfFloat },
    { &ScalarConverter::isDouble, &ScalarConverter::printIfDouble },
    { &ScalarConverter::isInf, &ScalarConverter::printIfInf },
    { &ScalarConverter::isNan, &ScalarConverter::printIfNan }
};

// ***CANONICAL CONSTRUCTORS***

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
       *this = rhs;
    }
    return *this;
};

ScalarConverter::~ScalarConverter(void) {
    std::cout << "ScalarConverter class destructor called." << std::endl;
};

// ***METHODS**

void ScalarConverter::convert(const char* literal) {
    int i = -1;
    int j = 0;
    while (i == -1 && j < TOTAL_TYPES) {
		try {
        	i = (_matchFunctions[j].fptrCheck)(literal);
		}
		catch (std::exception& e) {
			errorln(e.what());
            return ;
		}
        if (i != -1) {
            (_matchFunctions[j].fptrPrint)(literal);
        }
        j++;
    }
};

int ScalarConverter::isChar(const char* literal) {
    if (strlen(literal) == 1 && isprint(*literal) && !isdigit(*literal)) {
        println(MAGENTA << "It`s a char.");
        return (0);
    }
    else
        return (-1);    
};

int ScalarConverter::isInt(const char* literal) {
    std::string literalAsString = static_cast<std::string>(literal);
    println(RED << "After cast: " << literalAsString);
    for (size_t i = (literal[0] == '-' || literal[0] == '+') ? i = 1 : i = 0;
        i < literalAsString.length(); i++) {
            if (!isdigit(literal[i])) // check for non digits
                return (-1);
        }
    int atoiedLiteral = atoi(literal);
    println(GREEN << "After atoi: " << atoiedLiteral);
    std::stringstream stream;
    stream << atoiedLiteral;
    std::string atoiedLiteralAsString;
    stream >> atoiedLiteralAsString;
    if (literalAsString == atoiedLiteralAsString){ //check for potential overflow
        println(MAGENTA << "It's a int.");
        return (1);
    }
	throw ScalarConverter::IntOverflowTypeException();
    return (-1);
};

int ScalarConverter::isFloat(const char* literal) {
    int count = 0;
    std::string literalAsString = static_cast<std::string>(literal);
    println(RED << "After float cast: " << literalAsString);
    for (size_t i = (literal[0] == '-' || literal[0] == '+') ? i = 1 : i = 0;
    i < literalAsString.length(); i++) {
        if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f' && literal[i] != 'F') // check for non digits
            return (-1);
        if (literal[i] == '.')
            count ++;
    }
    if (count > 1) {
		std::cout << "Broken float: " << count << std::endl;
        return (-1);
	}
    (literalAsString.length() - literalAsString.rfind('.')) - 2 ? // calculate precision
    _precision = (literalAsString.length() - literalAsString.rfind('.')) - 2 : _precision = 1;
    if ((literalAsString[literalAsString.length() -1] == 'f'
	|| literalAsString[literalAsString.length() -1] == 'F') && count == 1) {
        println(MAGENTA << "It`s a float.");
        return (2);
    }
    return (-1);
};

int ScalarConverter::isDouble(const char* literal) {
    int count = 0;
    std::string literalAsString = static_cast<std::string>(literal);
    println(RED << "After double cast: " << literalAsString);
    for (size_t i = (literal[0] == '-' || literal[0] == '+') ? i = 1 : i = 0;
    i < literalAsString.length(); i++) {
        if (!isdigit(literal[i]) && literal[i] != '.') // check for non digits
            return (-1);
        if (literal[i] == '.')
            count ++;
    }
    (literalAsString.length() - literalAsString.rfind('.')) - 1 ? // calculate precision
    _precision = (literalAsString.length() - literalAsString.rfind('.')) - 1 : _precision = 1;
    if (count == 1) {
        println(MAGENTA << "It`s a double.");
        return (3);    
    }
    return (-1);
};

int ScalarConverter::isInf(const char* literal) {
    if (std::isinf(atof(literal))){
        println(ORANGE << "This is INF: " << static_cast<std::string>(literal));
        return (4);
    }
    return (-1);
};

int ScalarConverter::isNan(const char* literal) {
    if (std::isnan(atof(literal))){
        println(ORANGE << "This is NAN: " << static_cast<std::string>(literal));
        return (5);
    }
    return (-1);
};

void ScalarConverter::printIfChar(const char* literal) {
    char converted = literal[0];
    println(GREEN << "char: " << BLUE << "'" << converted << "'");   // NON DISPLAYABLE
    println(GREEN << "int: " << BLUE << static_cast<int>(converted));  
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');  
    println(GREEN << "double: " << BLUE << static_cast<double>(converted));  
};

void ScalarConverter::printIfInt(const char* literal) {
    std::string literalAsString = static_cast<std::string>(literal);
	int converted = atoi(literal);
	if (isprint(converted)) {
    	println(GREEN << "char: " << BLUE << "'" << static_cast<char>(converted) << "'"); // NON DISPLAYABLE
	}
	else if (converted <= 32) {
    	println(GREEN << "char: " << BLUE << "Non Displayable"); // NON DISPLAYABLE
	}
	else
    	println(GREEN << "char: " << BLUE << "impossible"); // NON DISPLAYABLE
    println(GREEN << "int: " << BLUE << converted);  
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');
    println(GREEN << "double: " << BLUE << static_cast<double>(converted));
};

void ScalarConverter::printIfFloat(const char* literal) {
    float converted = atof(literal);
	if (isprint(converted)) {
    	println(GREEN << "char: " << BLUE << "'" << static_cast<char>(converted) << "'"); // NON DISPLAYABLE
	}
	else if (converted <= 32) {
    	println(GREEN << "char: " << BLUE << "Non Displayable"); // NON DISPLAYABLE
	}
	else
    	println(GREEN << "char: " << BLUE << "impossible"); // NON DISPLAYABLE
    println(GREEN << "int: " << BLUE << static_cast<int>(converted)); 
    std::cout << std::fixed;
    std::cout.precision(_precision);
    println(GREEN << "float: " << BLUE << converted << 'f');
    println(GREEN << "double: " << BLUE << static_cast<double>(converted));  
};

void ScalarConverter::printIfDouble(const char* literal) {
	println(ORANGE << "GOT INSIDE DOUBLE");
    double converted = atof(literal);
	if (isprint(converted)) {
    	println(GREEN << "char: " << BLUE << "'" << static_cast<char>(converted) << "'"); // NON DISPLAYABLE
	}
	else if (converted <= 32) {
    	println(GREEN << "char: " << BLUE << "Non Displayable"); // NON DISPLAYABLE
	}
	else
    	println(GREEN << "char: " << BLUE << "impossible"); // NON DISPLAYABLE
    println(GREEN << "int: " << BLUE << static_cast<int>(converted));
    std::cout << std::fixed;
    std::cout.precision(_precision);
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');
    println(GREEN << "double: " << BLUE << converted);  
};

void ScalarConverter::printIfInf(const char* literal) {
    double converted = atof(literal);
    println(GREEN << "char: " << "impossible");  
    println(GREEN << "int: " << "impossible");
    std::cout << std::fixed;
    std::cout.precision(_precision);
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');
    println(GREEN << "double: " << BLUE << converted);  
};

void ScalarConverter::printIfNan(const char* literal) {
    double converted = atof(literal);
    println(GREEN << "char: " << "impossible");  
    println(GREEN << "int: " << "impossible");
    std::cout << std::fixed;
    std::cout.precision(_precision);
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');
    println(GREEN << "double: " << BLUE << converted);  
};

const char* ScalarConverter::IntOverflowTypeException::what() const throw() {
    return ("Input is over int type limits.");
};