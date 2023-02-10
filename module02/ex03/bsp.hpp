#ifndef BSP_HPP
# define BSP_HPP

# include "Point.hpp"

bool	isIntersecting(const Point &s1, const Point &e1, const Point &s2, const Point &e2);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
