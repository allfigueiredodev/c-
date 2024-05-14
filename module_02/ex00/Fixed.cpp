#include "Fixed.class.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed(void){
	this->_i = 0;
	std::cout << "Default constructor called" << std::endl;
};

// Fixed::Fixed(const Fixed& Fixed) : _i(Fixed._i) {
Fixed::Fixed(const Fixed& Fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = Fixed;
};

Fixed& Fixed::operator=(const Fixed& Fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &Fixed) {
		this->_i = Fixed.getRawBits();
	}
	return *this;
};

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_i);
}

void Fixed::setRawBits(int const raw) {
	this->_i = raw;
}
