#include "Point.class.hpp"

Point::Point(void) : _x(0) , _y(0) {};

Point::~Point(void) {};

Point::Point(const float x , const float y) : _x(x) , _y(y) {};

Point&	Point::operator=(const Point& rhs) {
	if (this != &rhs) {
		(Fixed&)_x = Fixed(rhs.getX());
		(Fixed&)_y = Fixed(rhs.getY());
	}
	return (*this);
};

Point::Point(const Point& Point) {
	*this = Point;
};

Fixed Point::getX(void) const {
	return (_x);
};

Fixed Point::getY(void) const {
	return (_y);
};
