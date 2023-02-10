#include <iostream>
#include "Point.hpp"

//                              (x1, y1)        (x2, y2)         (x3, y3)          (x4, y4)
bool	isIntersecting(const Point &s1, const Point &e1, const Point &s2, const Point &e2)
{
	std::cout << "line " << s1 << " - " << e1 << " vs line " << s2 << " - " << e2 << std::endl;
	Fixed A((e1.getY() - s1.getY()) * (e2.getX() - s2.getX()) - (e1.getX() - s1.getX()) * (e2.getY() - s2.getY()));
	if (A == 0)
		return (false);
	// If A = 0, then the line segments are either parallel or coincident and do not intersect.
	// Otherwise, the intersection point (x, y) can be calculated as follows:
	Fixed B((e2.getY() - s2.getY()) * (s1.getX() - s2.getX()) - (e2.getX() - s2.getX()) * (s1.getY() - s2.getY()));
	Fixed C((e1.getY() - s1.getY()) * (s1.getX() - s2.getX()) - (e1.getX() - s1.getX()) * (s1.getY() - s2.getY()));
	if (B >= 0 && B <= 1 && C >= 0 && C <= 1)
		return (true);
	else
		return (false);
}
