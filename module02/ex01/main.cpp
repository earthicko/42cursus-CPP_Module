#include <iostream>
#include "Fixed.hpp"

void	testVal(int val)
{
	Fixed fixed(val);
	std::cout << "to int  : " << fixed.toFloat() << std::endl;
	std::cout << "to float: " << fixed.toFloat() << std::endl;
	std::cout << "ostream : " << fixed << std::endl;
	std::cout << "======================" << std::endl;
}

void	testVal(float val)
{
	Fixed fixed(val);
	std::cout << "to int  : " << fixed.toInt() << std::endl;
	std::cout << "to float: " << fixed.toFloat() << std::endl;
	std::cout << "ostream : " << fixed << std::endl;
	std::cout << "======================" << std::endl;
}

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	std::cout.precision(20);
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
	testVal((float)8000000.5898);
	testVal((float)(18 - 7000.2666));
	return (0);
}
