#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
					Point(void);
					Point(const Point &orig);
					~Point(void);
		Point		&operator=(const Point &orig);

					Point(const float xcoord, const float ycoord);

		Fixed		getX(void) const;
		Fixed		getY(void) const;

	private:
		const Fixed	x;
		const Fixed	y;
};

#endif
