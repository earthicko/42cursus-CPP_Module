#include <iostream>
#include "Fixed.hpp"

const int	Fixed::_nfracts = 8;

Fixed::Fixed(void): _bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &orig): _bits(orig._bits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &orig)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_bits = orig._bits;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_bits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_bits = raw;
}
