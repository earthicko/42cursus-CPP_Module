#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

float	getDistanceLineToPoint(const Point &s, const Point &e, const Point &p)
{
	float	x1, y1, x2, y2, xp, yp, t, projX, projY, segLenSq;

	x1 = s.getX().toFloat();
	y1 = s.getY().toFloat();
	x2 = e.getX().toFloat();
	y2 = e.getY().toFloat();
	xp = p.getX().toFloat();
	yp = p.getY().toFloat();
	segLenSq = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	if (Fixed::getE() > segLenSq)
		return (sqrt(pow(xp - x1, 2) + pow(yp - y1, 2)));
	t = ((xp - x1) * (x2 - x1) + (yp - y1) * (y2 - y1)) / segLenSq;
	t = fmax(0, fmin(1, t));
	projX = x1 + t * (x2 - x1);
	projY = y1 + t * (y2 - y1);
	return (sqrt(pow(xp - projX, 2) + pow(yp - projY, 2)));
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
		if (Fixed::getE() > getDistanceLineToPoint(*(l[i][0]), *(l[i][1]), point))
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
