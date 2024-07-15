#include "Classes/RPN/RPN.hpp"

RPN::RPN(void) {
    std::cout << "RPN class default constructor called." << std::endl;
};

RPN::RPN(const RPN& RPN) {
    std::cout << "RPN class copy constructor called." << std::endl;
    *this = RPN;
};

RPN& RPN::operator=(const RPN& rhs) {
    std::cout << "RPN class copy assign operator called." << std::endl;
    if (this != &rhs){
        *this = rhs;
    }
    return *this;
};

RPN::~RPN(void) {
    std::cout << "RPN class destructor called." << std::endl;
};

void    RPN::calc(char* expression) {

};

void    RPN::parseExpression(char* expression) {
    std::string             buffer;
    std::stringstream       stream(expression);

    while (stream >> buffer) {
        // isOperand...
            // *add to stack
        // isOperator...
            // *check if the stack has at least two indexes
                //* !if throw error
                //* if do the math, push the result to the top of the stack 
    }
};
