#include "Polymorphism.h"

WrongAnimal::WrongAnimal(void) : _type("Wrong Animal") {
    std::cout << "WrongAnimal class default constructor called." << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal){
    std::cout << "WrongAnimal class copy constructor called." << std::endl;
    *this = WrongAnimal;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal){
    std::cout << "WrongAnimal class copy assign operator called." << std::endl;
    if (this != &WrongAnimal){
        this->_type = WrongAnimal._type;
    }
    return *this;
};

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal class destructor called." << std::endl;
};

void WrongAnimal::makeSound(void) const {
	std::cout << "*unrecognized and weird animal noise*" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (this->_type);
};