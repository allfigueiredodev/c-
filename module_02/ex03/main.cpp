#include <iostream>
#include "Point.hpp"

int main (void)
{
	Point const a(0, 0);
	Point const b(2, 0);
	Point const c(1, 2);
	Point const point(0.5, 1.5);
	
	if (bsp(a, b, c, point))
		std::cout << GREEN << "The point is inside the triangle" << DFT << std::endl;
	else
		std::cout << RED << "The point is outside the triangle" << DFT << std::endl;
	return (0);
}