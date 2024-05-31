
#include "Polymorphism.h"

WrongCat::WrongCat(void) {
    std::cout << "WrongCat class default constructor called." << std::endl;
};

WrongCat::WrongCat(const WrongCat& WrongCat) {
    std::cout << "WrongCat class copy constructor called." << std::endl;
    *this = WrongCat;
};

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    std::cout << "WrongCat class copy assign operator called." << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
};

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat class destructor called." << std::endl;
};

void WrongCat::makeSound(void) const {
	std::cout << "*Weird cat noise*" << std::endl;
};
