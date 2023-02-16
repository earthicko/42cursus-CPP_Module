#include <iostream>
#include <limits.h>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a((float)1.092);
	Fixed	b((float)1.092);
	Fixed	c((float)-1.092);
	Fixed	d((float)-49817);

	std::cout << "(a == b): ";
	std::cout << (a == b) << std::endl;
	std::cout << "(a > b): ";
	std::cout << (a > b) << std::endl;
	std::cout << "(a > c): ";
	std::cout << (a > c) << std::endl;
	std::cout << "(a != b): ";
	std::cout << (a != b) << std::endl;
	std::cout << "(a != c): ";
	std::cout << (a != c) << std::endl;
	std::cout << "(a > d): ";
	std::cout << (a > d) << std::endl;

	std::cout << "a++: ";
	std::cout << a++ << std::endl;
	std::cout << "++b: ";
	std::cout << ++b << std::endl;
	std::cout << "a++: ";
	std::cout << a++ << std::endl;
	std::cout << "++b: ";
	std::cout << ++b << std::endl;

	std::cout << "(Fixed(4) + Fixed(-2)): ";
	std::cout << (Fixed(4) + Fixed(-2)) << std::endl;
	std::cout << "(Fixed(4) - Fixed(-2)): ";
	std::cout << (Fixed(4) - Fixed(-2)) << std::endl;
	std::cout << "(Fixed(4) * Fixed(-2)): ";
	std::cout << (Fixed(4) * Fixed(-2)) << std::endl;
	std::cout << "(Fixed(4) / Fixed(-2)): ";
	std::cout << (Fixed(4) / Fixed(-2)) << std::endl;
	std::cout << "(Fixed(-2) + Fixed(4)): ";
	std::cout << (Fixed(-2) + Fixed(4)) << std::endl;
	std::cout << "(Fixed(-2) - Fixed(4)): ";
	std::cout << (Fixed(-2) - Fixed(4)) << std::endl;
	std::cout << "(Fixed(-2) * Fixed(4)): ";
	std::cout << (Fixed(-2) * Fixed(4)) << std::endl;
	std::cout << "(Fixed(-2) / Fixed(4)): ";
	std::cout << (Fixed(-2) / Fixed(4)) << std::endl;
	std::cout << "(Fixed((float)-2.234) + Fixed((float)4.234)): ";
	std::cout << (Fixed((float)-2.234) + Fixed((float)4.234)) << std::endl;
	std::cout << "(Fixed((float)-2.234) - Fixed((float)4.234)): ";
	std::cout << (Fixed((float)-2.234) - Fixed((float)4.234)) << std::endl;
	std::cout << "(Fixed((float)-2.234) * Fixed((float)4.234)): ";
	std::cout << (Fixed((float)-2.234) * Fixed((float)4.234)) << std::endl;
	std::cout << "(Fixed((float)-2.234) / Fixed((float)4.234)): ";
	std::cout << (Fixed((float)-2.234) / Fixed((float)4.234)) << std::endl;

	std::cout << "Fixed::max(Fixed(-2), Fixed(4)): ";
	std::cout << Fixed::max(Fixed(-2), Fixed(4)) << std::endl;
	std::cout << "Fixed::max(Fixed(8), Fixed(4)): ";
	std::cout << Fixed::max(Fixed(8), Fixed(4)) << std::endl;
	std::cout << "Fixed::min(Fixed(-2), Fixed(4)): ";
	std::cout << Fixed::min(Fixed(-2), Fixed(4)) << std::endl;
	std::cout << "Fixed::min(Fixed(8), Fixed(4)): ";
	std::cout << Fixed::min(Fixed(8), Fixed(4)) << std::endl;

	return (0);
}
