#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

void	testBsp(const Point &a, const Point &b, const Point &c, const Point &s)
{
	std::cout << s << " in Tri " << a << ", " << b << ", " << c << ": ";
	std::cout << bsp(a, b, c, s) << std::endl;
}

int	main(void)
{
	for (int x = -1; x <= 4; x++)
	{
		for (int y = -1; y <= 4; y++)
			testBsp(Point(0, 0), Point(3, 0), Point(0, 3), Point(x, y));
	}
	return (0);
}
