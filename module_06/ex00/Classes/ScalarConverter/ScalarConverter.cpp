/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:41:47 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 13:41:50 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.h"
#include "ScalarConverter.hpp"
#include "Classes/ScalarConverter/ScalarConverter.hpp"

int ScalarConverter::_precision = 1;

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
        return (0);
    }
    else
        return (-1);    
};

int ScalarConverter::isInt(const char* literal) {
    std::string literalAsString = static_cast<std::string>(literal);
    for (size_t i = (literal[0] == '-' || literal[0] == '+') ? i = 1 : i = 0;
        i < literalAsString.length(); i++) {
            if (!isdigit(literal[i]))
                return (-1);
        }
    int atoiedLiteral = atoi(literal);
    std::stringstream stream;
    stream << atoiedLiteral;
    std::string atoiedLiteralAsString;
    stream >> atoiedLiteralAsString;
    if (literalAsString == atoiedLiteralAsString){
        return (1);
    }
	throw ScalarConverter::IntOverflowTypeException();
    return (-1);
};

int ScalarConverter::isFloat(const char* literal) {
    int count = 0;
    std::string literalAsString = static_cast<std::string>(literal);
    for (size_t i = (literal[0] == '-' || literal[0] == '+') ? i = 1 : i = 0;
    i < literalAsString.length(); i++) {
        if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f' && literal[i] != 'F')
            return (-1);
        if (literal[i] == '.')
            count ++;
    }
    if (count > 1) {
		throw ScalarConverter::BrokenFloatException();
		std::cout << "Broken float: " << count << std::endl;
        return (-1);
	}
    (literalAsString.length() - literalAsString.rfind('.')) - 2 ?
    _precision = (literalAsString.length() - literalAsString.rfind('.')) - 2 : _precision = 1;
    if ((literalAsString[literalAsString.length() -1] == 'f'
	|| literalAsString[literalAsString.length() -1] == 'F') && count == 1) {
        return (2);
    }
    return (-1);
};

int ScalarConverter::isDouble(const char* literal) {
    int count = 0;
    std::string literalAsString = static_cast<std::string>(literal);
    for (size_t i = (literal[0] == '-' || literal[0] == '+') ? i = 1 : i = 0;
    i < literalAsString.length(); i++) {
        if (!isdigit(literal[i]) && literal[i] != '.')
            return (-1);
        if (literal[i] == '.')
            count ++;
    }
    (literalAsString.length() - literalAsString.rfind('.')) - 1 ?
    _precision = (literalAsString.length() - literalAsString.rfind('.')) - 1 : _precision = 1;
    if (count == 1) {
        return (3);    
    }
	else if (count > 1)
		throw ScalarConverter::BrokenFloatException();
    return (-1);
};

int ScalarConverter::isInf(const char* literal) {
    if (std::isinf(atof(literal))) {
        return (4);
    }
    return (-1);
};

int ScalarConverter::isNan(const char* literal) {
    if (std::isnan(atof(literal))) {
        return (5);
    }
    return (-1);
};

void ScalarConverter::printIfChar(const char* literal) {
    char converted = literal[0];
    println(GREEN << "char: " << BLUE << "'" << converted << "'");
    println(GREEN << "int: " << BLUE << static_cast<int>(converted)); 
	std::cout << std::fixed;
    std::cout.precision(1);
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');  
    println(GREEN << "double: " << BLUE << static_cast<double>(converted));  
};

void ScalarConverter::printIfInt(const char* literal) {
	int converted = atoi(literal);
	if (converted >= 32 && converted < 127) {
    	println(GREEN << "char: " << BLUE << "'" << static_cast<char>(converted) << "'");
	}
	else if (converted < 32 || converted >= 127) {
    	println(GREEN << "char: " << BLUE << "Non Displayable");
	}
	else
    	println(GREEN << "char: " << BLUE << "impossible");
	std::cout << std::fixed;
    std::cout.precision(1);
    println(GREEN << "int: " << BLUE << converted);  
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');
    println(GREEN << "double: " << BLUE << static_cast<double>(converted));
};

void ScalarConverter::printIfFloat(const char* literal) {
	double converted = atof(literal);
	if (converted >= 32 && converted < 127) {
    	println(GREEN << "char: " << BLUE << "'" << static_cast<char>(converted) << "'");
	}
	else if (converted <= 32 || converted == 127) {
		println(GREEN << "char: " << BLUE << "Non Displayable");
	}
	else
    	println(GREEN << "char: " << BLUE << "impossible");
	if (converted < static_cast<float>(INT_MIN) || converted > static_cast<float>(INT_MAX) || converted == -1) {
    	println(GREEN << "int: " << BLUE << "impossible");
	}
	else
    	println(GREEN << "int: " << BLUE << static_cast<int>(converted));
    std::cout << std::fixed;
    std::cout.precision(_precision);
    println(GREEN << "float: " << BLUE << static_cast<float>(converted) << 'f');
    println(GREEN << "double: " << BLUE << converted);
};

void ScalarConverter::printIfDouble(const char* literal) {
    double converted = atof(literal);
	if (converted >= 32 && converted < 127) {
    	println(GREEN << "char: " << BLUE << "'" << static_cast<char>(converted) << "'");
	}
	else if (converted <= 32 || converted == 127) {
    	println(GREEN << "char: " << BLUE << "Non Displayable");
	}
	else
    	println(GREEN << "char: " << BLUE << "impossible");
	if (converted < static_cast<double>(INT_MIN) || converted > static_cast<double>(INT_MAX) || converted == -1) {
    	println(GREEN << "int: " << BLUE << "impossible");
	}
	else
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

const char* ScalarConverter::BrokenFloatException::what() const throw() {
    return ("More than one decimal point found.");
};
