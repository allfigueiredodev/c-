#include "Fixed.class.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed(void){
	this->_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& Fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = Fixed;
};

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = i << _fracBits;
};

Fixed::Fixed(const float i) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = (int)roundf(i * (1 << _fracBits));
};

Fixed& Fixed::operator=(const Fixed& Fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &Fixed) {
		this->_rawBits = Fixed.getRawBits();
	}
	return *this;
};

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
	return (this->_rawBits);
};

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
};

float Fixed::toFloat( void ) const {
	return ((float)getRawBits() / float(1 << _fracBits));
};

int Fixed::toInt( void ) const {
	return (getRawBits() >> _fracBits);
};

std::ostream& operator<<(std::ostream& o,const Fixed& fixed)
{
	o << (fixed.toFloat());
	return (o);
};