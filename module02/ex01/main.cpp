#include <iostream>
#include "Fixed.hpp"
#include "bitUtils.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	prettyPrintBits(1);
	prettyPrintBits(2);
	prettyPrintBits(-8);
	prettyPrintBits(-70002666);

	// c = b;
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;

	// a.setRawBits(17110);
	// b.setRawBits(-70002666);
	// c.setRawBits(1332909);

	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;

	return 0;
}
