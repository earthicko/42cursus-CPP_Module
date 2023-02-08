#include <iostream>
#include <limits.h>
#include "Fixed.hpp"
#include "bitUtils.hpp"

void	testVal(int val)
{
	Fixed fixed(val);
	std::cout << "to int  : " << fixed.toFloat() << std::endl;
	std::cout << "to float: " << fixed.toFloat() << std::endl;
	std::cout << "ostream : " << fixed << std::endl;
}

void	testVal(float val)
{
	Fixed fixed(val);
	std::cout << "to int  : " << fixed.toInt() << std::endl;
	std::cout << "to float: " << fixed.toFloat() << std::endl;
	std::cout << "ostream : " << fixed << std::endl;
}

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	testVal((int)0);
	testVal((int)8);
	testVal((int)-21);
	testVal((float)0.0);
	testVal((float)0.0);
	testVal((float)0.5);
	testVal((float)0.25);
	testVal((float)2.0);
	testVal((float)4.5);
	testVal((float)8.25);
	testVal((float)-2.0);
	testVal((float)-4.5);
	testVal((float)-8.25);
	testVal((float)12.58);
	return 0;
}
