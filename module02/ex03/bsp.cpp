#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

Fixed	getDistanceSqLineToPoint(const Point &s, const Point &e, const Point &p)
{
	Fixed	x1, y1, x2, y2, xp, yp, t, projX, projY, segLenSq;

	x1 = s.getX();
	y1 = s.getY();
	x2 = e.getX();
	y2 = e.getY();
	xp = p.getX();
	yp = p.getY();
	segLenSq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	if (Fixed::getE() > segLenSq)
		return ((xp - x1) * (xp - x1) + (yp - y1) * (yp - y1));
	t = ((xp - x1) * (x2 - x1) + (yp - y1) * (y2 - y1)) / segLenSq;
	t = Fixed::max(0, Fixed::min(1, t));
	projX = x1 + t * (x2 - x1);
	projY = y1 + t * (y2 - y1);
	return ((xp - projX) * (xp - projX) + (yp - projY) * (yp - projY));
}

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

	for (int i = 0; i < 3; i++)
	{
		if (Fixed::getE() > getDistanceSqLineToPoint(*(l[i][0]), *(l[i][1]), point))
			return (true);
	}
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
