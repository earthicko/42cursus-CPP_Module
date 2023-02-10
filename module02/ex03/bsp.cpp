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
	Fixed		xmax;
	Point		testSegEnd;
	int			nIntersection;
	const Point	*l[3][2] = {{&a, &b}, {&b, &c}, {&c, &a}};

	xmax = getMaxXCoord(a, b, c) + Fixed::getE() * 2;
	testSegEnd = Point(xmax, point.getY());
	nIntersection = 0;
	for (int i = 0; i < 3; i++)
	{
		if (isIntersecting(*(l[i][0]), *(l[i][1]), point, testSegEnd))
			nIntersection++;
	}
	return (nIntersection % 2 == 1);
}
