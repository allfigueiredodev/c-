
#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include "scalar.h"

class ScalarConverter {

    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& ScalarConverter);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter(void);

    typedef struct s_matchFunctions {
        // int (*fptr)(std::string value);
        // void (*fptr)(void);
    } t_matchFunctions;

    static t_matchFunctions matchFunctions[4];
    static void convert(std::string value);
    static bool ScalarConverter::isChar(std::string value);
    static bool isInt(std::string value);
    static bool isFloat(std::string value);
    static bool isDouble(std::string value);
};

#endif

