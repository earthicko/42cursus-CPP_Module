#include <iostream>
#include "Point.hpp"

// ccw -> 1, collinear -> 0, cw -> -1
int	ccw(const Point &p1, const Point &p2, const Point &p3)
{
	Fixed dx12 = p2.getX() - p1.getX();
	Fixed dy13 = p3.getY() - p1.getY();
	Fixed dx13 = p3.getX() - p1.getX();
	Fixed dy12 = p2.getY() - p1.getY();
	Fixed cross_product = dx12 * dy13 - dx13 * dy12;

	if (cross_product > 0)
		return (1);
	else if (cross_product < 0)
		return (-1);
	else
		return (0);
}

// https://gaussian37.github.io/math-algorithm-line_intersection/
bool	isIntersecting(Point s1, Point e1, Point s2, Point e2)
{
	int		l1_l2;
	int		l2_l1;

	l1_l2 = ccw(s1, e1, s2) * ccw(s1, e1, e2);
	l2_l1 = ccw(s2, e2, s1) * ccw(s2, e2, e1);
	if (l1_l2 == 0 && l2_l1 == 0)
		return (false);
	else
		return ((l1_l2 <= 0) && (l2_l1 <= 0));
}
