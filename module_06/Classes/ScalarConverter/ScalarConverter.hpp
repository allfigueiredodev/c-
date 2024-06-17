
#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include "scalar.h"

class ScalarConverter {

    private:

        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& ScalarConverter);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter(void);
    

        static int isChar(const char* literal);
        static int isInt(const char* literal);
        static int isFloat(const char* literal);
        static int isDouble(const char* literal);
        static void printIfChar(const char* literal);
        static void printIfInt(const char* literal);
        static void printIfFloat(const char* literal);
        static void printIfDouble(const char* literal);
        typedef struct s_matchFunctions {
            int (*fptrCheck)(const char* literal);
            void (*fptrPrint)(const char* literal);
        } t_matchFunctions;
        static t_matchFunctions _matchFunctions[4];
    
    public:

        static void convert(const char* literal);

};

#endif

