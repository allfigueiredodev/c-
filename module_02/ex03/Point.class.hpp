#ifndef POINT_CLASS_HPP
#define	POINT_CLASS_HPP

#include "Fixed.class.hpp"

class Point {

	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point(void) : _x(0) , _y(0) {};
		~Point(void);
		Point(const float x , const float y);
		Point(const Point& Point);
		Point&	operator=(const Point& Point) ;
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif