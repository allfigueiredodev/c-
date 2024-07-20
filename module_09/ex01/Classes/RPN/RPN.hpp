/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:21:39 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/19 22:21:41 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <stack>

#define println(x) std::cout << x << DFT << std::endl;
#define errorln(x) std::cerr << RED << x << DFT << std::endl;

#define RED     	"\033[1;31m"
#define GREEN   	"\033[1;32m"
#define CYAN    	"\033[1;36m"
#define ORANGE		"\033[0;38;5;166m"
#define DFT   		"\033[0m"

class RPN {

    public:
        RPN(void);
        ~RPN(void);
        void calc(char* expression);

    private:
        RPN(const RPN& RPN);
        RPN& operator=(const RPN& rhs);
        void _parseExpression(std::string expression);
		void _doTheMath(char mOperator);

        std::stack<int> _RPNStack;

};

#endif

