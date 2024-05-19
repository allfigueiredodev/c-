#include "Point.class.hpp"

Point::Point(void) {};

Point::~Point(void) {};

Point::Point(const float x , const float y) : _x(x) , _y(y) {};

Point&	Point::operator=(const Point& Point) {
	if (this != &Point) {
		this->_x = Point.getX();
		this->_y = Point.getY();
	}
	return (*this);
};

Point::Point(const Point& Point) {
	*this = Point;
};

Fixed Point::getX(void) {
	return (_x);
};

Fixed Point::getY(void) {
	return (_y);
};