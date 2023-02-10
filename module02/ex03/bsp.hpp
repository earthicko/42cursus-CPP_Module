#ifndef BSP_HPP
# define BSP_HPP

# include "Point.hpp"

bool	isIntersecting(Point s1, Point e1, Point s2, Point e2);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
