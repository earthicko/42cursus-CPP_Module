#include "Point.hpp"

Point::Point(void):
	x(0),
	y(0)
{
}

Point::Point(const Point &orig):
	x(orig.x),
	y(orig.y)
{
}

Point::~Point(void)
{
}

Point	&Point::operator=(const Point &orig)
{
	if (this != &orig)
	{
		const_cast<Fixed&>(x) = orig.getX();
		const_cast<Fixed&>(y) = orig.getY();
	}
	return (*this);
}

Point::Point(const float xcoord, const float ycoord):
	x(xcoord),
	y(ycoord)
{
}

Point::Point(const Fixed &xcoord, const Fixed &ycoord):
	x(xcoord),
	y(ycoord)
{
}

Fixed	Point::getX(void) const
{
	return (x);
}

Fixed	Point::getY(void) const
{
	return (y);
}

bool	Point::operator>(const Point &other) const
{
	if (x == other.x)
		return (y > other.y);
	else
		return (x > other.x);
}

bool	Point::operator<(const Point &other) const
{
	if (x == other.x)
		return (y < other.y);
	else
		return (x < other.x);
}

bool	Point::operator>=(const Point &other) const
{
	if (x == other.x)
		return (y >= other.y);
	else
		return (x >= other.x);
}

bool	Point::operator<=(const Point &other) const
{
	if (x == other.x)
		return (y <= other.y);
	else
		return (x <= other.x);
}

bool	Point::operator==(const Point &other) const
{
	return (x == other.x && y == other.y);
}

bool	Point::operator!=(const Point &other) const
{
	return (!((*this) == other));
}

std::ostream	&operator<<(std::ostream &os, const Point& point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return (os);
}
