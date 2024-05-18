#include "Fixed.class.hpp"

const int Fixed::_fracBits = 8;

// constructors & destructor

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
	return (*this);
};

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
};

// Arithmetic overload

Fixed Fixed::operator+(const Fixed& Fixed) const {
	std::cout << "Sum operator called" << std::endl;
	return (this->toFloat() + Fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& Fixed) const {
	std::cout << "minus operator called" << std::endl;
	return (this->toFloat() - Fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& Fixed) const {
	std::cout << "multiplication operator called" << std::endl;
	return (this->toFloat() * Fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& Fixed) const {
	std::cout << "division operator called" << std::endl;
	return (this->toFloat() / Fixed.toFloat());
}

// Comparison overload

bool Fixed::operator>(const Fixed& Fixed) const {
	if (this->_rawBits > Fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& Fixed) const {
	if (this->_rawBits < Fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& Fixed) const {
	if (this->_rawBits == Fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& Fixed) const {
	if (this->_rawBits != Fixed.getRawBits())
		return (true);
	return (false);
}

// Pre/Post increment/decrement overload

Fixed& Fixed::operator--(void) {
	--_rawBits;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	_rawBits--;
	return temp;
}

Fixed& Fixed::operator++(void) {
	++_rawBits;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_rawBits++;
	return temp;
}

// out stream overload

std::ostream& operator<<(std::ostream& o,const Fixed& fixed) {
	o << (fixed.toFloat());
	return (o);
};

// Getter & setter

int Fixed::getRawBits(void) const {
	return (this->_rawBits);
};

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
};

// Type converters

float Fixed::toFloat( void ) const {
	return ((float)getRawBits() / float(1 << _fracBits));
};

int Fixed::toInt( void ) const {
	return (getRawBits() >> _fracBits);
};

// Min/Max getters

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}