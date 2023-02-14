#include <iostream>
#include "Fixed.hpp"
#include "sizedef.hpp"

const int	Fixed::_nfracts = 8;
const int	Fixed::_subnormalOffset = FLOAT_BITPOS_EXP - (Fixed::_nfracts - FLOAT_EXP_SHIFT);

Fixed::Fixed(void): _bits(0)
{
}

Fixed::Fixed(const Fixed &orig): _bits(orig._bits)
{
}

Fixed::~Fixed(void)
{
}

Fixed	&Fixed::operator=(const Fixed &orig)
{
	if (this != &orig)
	{
		_bits = orig._bits;
	}
	return (*this);
}

Fixed::Fixed(const int val)
{
	_bits = val << _nfracts;
}

static int	getExpByte(const float val)
{
	int				bitrepr;
	unsigned char	lastByte;

	bitrepr = *((int *)&val);
	bitrepr = (bitrepr << 1);
	lastByte = ((unsigned char *)&bitrepr)[3];
	return ((int)lastByte);
}

static bool	isZero(const float val)
{
	int	mask;
	int	bitrepr;

	mask = ~(1 << FLOAT_BITPOS_SIGN);
	bitrepr = *((int *)&val) & mask;
	if (bitrepr == 0)
		return (true);
	return (false);
}

static bool	isInfOrNan(const float val)
{
	if (getExpByte(val) == FLOAT_EXP_MAX)
		return (true);
	return (false);
}

int	Fixed::fromFloatGetMantissa(const float val, int leadingBit, int exp)
{
	int	mantissa;
	int	expOffset;

	mantissa = *((int *)&val) & FLOAT_MANTISSA_MASK;
	mantissa |= (leadingBit << FLOAT_BITPOS_EXP);
	expOffset = FLOAT_BITPOS_EXP - _nfracts - exp;
	if (expOffset > 0)
		mantissa = mantissa >> (FLOAT_BITPOS_EXP - _nfracts - exp);
	else
	{
		for (int i = 0; i < -expOffset; i++)
			mantissa *= 2;
	}
	if (*((int *)&val) & (1 << FLOAT_BITPOS_SIGN))
		mantissa = -mantissa;
	return (mantissa);
}

Fixed::Fixed(const float val)
{
	int	exp;
	int	leadingBit;
	int	mantissa;

	if (isZero(val))
	{
		_bits = 0;
		return ;
	}
	if (isInfOrNan(val))
	{
		std::cerr << "Input float is either inf or NaN." << std::endl;
		_bits = 0;
		return ;
	}
	leadingBit = 1;
	exp = getExpByte(val) - FLOAT_EXP_SHIFT;
	if (getExpByte(val) == 0)
	{
		leadingBit = 0;
		exp = 1 - FLOAT_EXP_SHIFT;
	}
	mantissa = Fixed::fromFloatGetMantissa(val, leadingBit, exp);
	_bits = mantissa;
}
