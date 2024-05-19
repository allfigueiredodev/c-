#ifndef POINT_CLASS_HPP
#define	POINT_CLASS_HPP

#include "Fixed.hpp"

class Point {

	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point(void) : _x(0) , _y(0) {};
		~Point(void);
		Point(const float x , const float y);
		Point(const Point& Point);
		Point&	operator=(const Point& Point);
		Fixed getX(void);
		Fixed getY(void);
};

#endif