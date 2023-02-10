#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

Fixed	getMaxXCoord(const Point &a, const Point &b, const Point &c)
{
	Fixed	max;

	max = Fixed::max(a.getX(), b.getX());
	max = Fixed::max(max, c.getX());
	return (max);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	xmax;
	Point	testSegEnd;
	int		i;

	xmax = getMaxXCoord(a, b, c) + Fixed::getE() * 2;
	std::cout << xmax << std::endl;
	testSegEnd = Point(xmax, point.getY());
	std::cout << isIntersecting(a, b, point, testSegEnd) << std::endl;
	std::cout << isIntersecting(b, c, point, testSegEnd) << std::endl;
	std::cout << isIntersecting(c, a, point, testSegEnd) << std::endl;
	i = 0;
	if (isIntersecting(a, b, point, testSegEnd))
		i++;
	if (isIntersecting(b, c, point, testSegEnd))
		i++;
	if (isIntersecting(c, a, point, testSegEnd))
		i++;
	return (i % 2 == 1);
}
