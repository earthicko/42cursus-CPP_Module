#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int	main(void)
{
	Point a(0.0, 0.0);
	Point b(3.0, 0.0);
	Point c(0.0, 3.0);
	Point s(1.0, 1.0);

	std::cout << bsp(a, b, c, s) << std::endl;
	return 0;
}
