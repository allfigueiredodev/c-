#include "Fixed.hpp"
#include "Point.class.hpp"

float tArea(Point vertA, Point vertB, Point vertC)
{
	return (
	std::abs(
		(vertA.getX() * (vertB.getY() - vertC.getY())).toFloat() + 
		(vertB.getX() * (vertC.getY() - vertA.getY())).toFloat() +
		(vertC.getX() * (vertA.getY() - vertB.getY())).toFloat() / 2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float totalArea = tArea(a, b, c);
	float areaA = tArea(point, b, c);
	float areaB = tArea(a, point, c);
	float areaC = tArea(a, b, point);

	float sum = areaA + areaB + areaC;
	if (areaA == 0 || areaB == 0 || areaC == 0)
		return (false);
	else if(sum == totalArea)
		return (true);
	return (false);
}