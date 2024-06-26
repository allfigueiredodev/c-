#ifndef POINT_HPP
#define	POINT_HPP

#include "Fixed.h"
#include "Fixed.hpp"

class Point {

	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point(void);
		~Point(void);
		Point(const float x , const float y);
		Point(const Point& Point);
		Point&	operator=(const Point& Point) ;
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif