#ifndef POINT_HPP
# define POINT_HPP

# include <ostream>
# include "Fixed.hpp"

class Point
{
	public:
					Point(void);
					Point(const Point &orig);
					~Point(void);
		Point		&operator=(const Point &orig);

					Point(const float xcoord, const float ycoord);
					Point(const Fixed &xcoord, const Fixed &ycoord);

		Fixed		getX(void) const;
		Fixed		getY(void) const;

		bool		operator>(const Point &other) const;
		bool		operator<(const Point &other) const;
		bool		operator>=(const Point &other) const;
		bool		operator<=(const Point &other) const;
		bool		operator==(const Point &other) const;
		bool		operator!=(const Point &other) const;

	private:
		const Fixed	x;
		const Fixed	y;
};

std::ostream	&operator<<(std::ostream &os, const Point& point);

#endif
