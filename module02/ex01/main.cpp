#include <iostream>
#include <limits.h>
#include "Fixed.hpp"
#include "bitUtils.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	a = Fixed((float)0.0);
	b = Fixed((float)0.5);
	c = Fixed((float)0.25);
	std::cout << "a to float: " << a.toFloat() << std::endl;
	std::cout << "a ostream : " << a << std::endl;
	std::cout << "b to float: " << b.toFloat() << std::endl;
	std::cout << "b ostream : " << b << std::endl;
	std::cout << "c to float: " << c.toFloat() << std::endl;
	std::cout << "c ostream : " << c << std::endl;

	a = Fixed((float)2.0);
	b = Fixed((float)4.5);
	c = Fixed((float)8.25);
	std::cout << "a to float: " << a.toFloat() << std::endl;
	std::cout << "a ostream : " << a << std::endl;
	std::cout << "b to float: " << b.toFloat() << std::endl;
	std::cout << "b ostream : " << b << std::endl;
	std::cout << "c to float: " << c.toFloat() << std::endl;
	std::cout << "c ostream : " << c << std::endl;

	a = Fixed((float)-2.0);
	b = Fixed((float)-4.5);
	c = Fixed((float)-8.25);
	std::cout << "a to float: " << a.toFloat() << std::endl;
	std::cout << "a ostream : " << a << std::endl;
	std::cout << "b to float: " << b.toFloat() << std::endl;
	std::cout << "b ostream : " << b << std::endl;
	std::cout << "c to float: " << c.toFloat() << std::endl;
	std::cout << "c ostream : " << c << std::endl;

	a = Fixed((int)-21);
	b = Fixed((int)0);
	c = Fixed((float)12.58);
	std::cout << "a to float: " << a.toFloat() << std::endl;
	std::cout << "a ostream : " << a << std::endl;
	std::cout << "b to float: " << b.toFloat() << std::endl;
	std::cout << "b ostream : " << b << std::endl;
	std::cout << "c to float: " << c.toFloat() << std::endl;
	std::cout << "c ostream : " << c << std::endl;

	return 0;
}
