#include "MutantStack.h"
#include "Classes/MutantStack/MutantStack.hpp"

// CANONICAL CONSTRUCTORS / DESTRUCTOR

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {
    std::cout << "MutantStack class default constructor called." << std::endl;
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& MutantStack) : std::stack<T>(MutantStack) {
    std::cout << "MutantStack class copy constructor called." << std::endl;
    *this = MutantStack;
};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs) {
    std::cout << "MutantStack class copy assign operator called." << std::endl;
    if (this != &rhs){
        *this = rhs;
    }
    return *this;
};

template <typename T>
MutantStack<T>::~MutantStack(void) {
    std::cout << "MutantStack class destructor called." << std::endl;
};

// METHODS

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator   MutantStack<T>::rbegin() {
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator   MutantStack<T>::rend() {
    return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator   MutantStack<T>::begin() const {
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator   MutantStack<T>::end() const {
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator   MutantStack<T>::rbegin() const {
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator   MutantStack<T>::rend() const {
    return std::stack<T>::c.rend();
}