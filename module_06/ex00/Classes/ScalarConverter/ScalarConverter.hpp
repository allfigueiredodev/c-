/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:41:56 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 13:42:01 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include "scalar.h"

class ScalarConverter {

    private:

        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& ScalarConverter);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter(void);
    
        static int  _precision;
        static int  isChar(const char* literal);
        static int  isInt(const char* literal);
        static int  isFloat(const char* literal);
        static int  isDouble(const char* literal);
        static int  isInf(const char* literal);
        static int  isNan(const char* literal);
        static void printIfChar(const char* literal);
        static void printIfInt(const char* literal);
        static void printIfFloat(const char* literal);
        static void printIfDouble(const char* literal);
        static void printIfInf(const char* literal);
        static void printIfNan(const char* literal);

        typedef struct s_matchFunctions {
            int (*fptrCheck)(const char* literal);
            void (*fptrPrint)(const char* literal);
        } t_matchFunctions;

        static t_matchFunctions _matchFunctions[6];

        class IntOverflowTypeException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

        class BrokenFloatException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
    
    public:

        static void convert(const char* literal);
};

#endif

