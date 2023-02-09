#include "Fixed.hpp"

static void	printIntUnsigned(std::ostream &os, int nb)
{
	int	digit;
	int	divider;

	divider = 1;
	while (!(-10 < nb / divider && nb / divider < 10))
		divider *= 10;
	while (divider > 0)
	{
		digit = nb / divider;
		nb = nb - (digit * divider);
		divider /= 10;
		if (digit < 0)
			digit = -digit;
		os << digit;
	}
}

std::ostream	&operator<<(std::ostream &os, const Fixed& fixed)
{
	int	whole;
	int	fract;
	int	nfracts;

	nfracts = fixed.getNFracts();
	whole = fixed.getRawBits();
	if (whole < 0)
	{
		os << "-";
		whole = -whole;
	}
	fract = whole & ((1 << nfracts) - 1);
	whole = whole >> nfracts;
	printIntUnsigned(os, whole);
	if (fract > 0)
	{
		os << ".";
		while (fract > 0)
		{
			fract *= 10;
			os << (fract >> nfracts);
			fract -= ((fract >> nfracts) << nfracts);
		}
	}
	return (os);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (_bits > other._bits);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (_bits < other._bits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_bits >= other._bits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_bits <= other._bits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_bits == other._bits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_bits != other._bits);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	temp;

	temp.setRawBits(_bits + other._bits);
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	temp;
	
	temp.setRawBits(_bits - other._bits);
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	long long	longbits;
	Fixed		temp;

	longbits = (long long)_bits * (long long)other._bits;
	longbits = longbits >> _nfracts;
	temp.setRawBits(longbits);
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	long long	longbits;
	Fixed		temp;

	longbits = ((long long)_bits << _nfracts) / (long long)other._bits;
	temp.setRawBits(longbits);
	return (temp);
}

Fixed	&Fixed::operator++(void)
{
	_bits++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	_bits--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}
