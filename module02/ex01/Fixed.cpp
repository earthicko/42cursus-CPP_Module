#include <iostream>
#include <limits.h>
#include "Fixed.hpp"
#include "bitUtils.hpp"
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
		std::cout << "Input float is either inf or NaN." << std::endl;
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
	mantissa = *((int *)&val) & FLOAT_MANTISSA_MASK;
	mantissa |= (leadingBit << FLOAT_BITPOS_EXP);
	mantissa = mantissa >> (FLOAT_BITPOS_EXP - _nfracts - exp);
	if (*((int *)&val) & (1 << FLOAT_BITPOS_SIGN))
		mantissa = -mantissa;
	_bits = mantissa;
}

int	Fixed::getRawBits(void) const
{
	return (_bits);
}

void	Fixed::setRawBits(int const raw)
{
	_bits = raw;
}

int	Fixed::getNFracts(void)
{
	return (_nfracts);
}

static void	toFloatSetSign(int *val, int *bitrepr)
{
	if (*val < 0)
	{
		(*bitrepr) |= (1 << FLOAT_BITPOS_SIGN);
		(*val) = -(*val);
	}
}

static int	getFirstBitIdx(int val)
{
	for (int i = INT_NBITS - 1; i >= 0; i--)
	{
		if (val & (1 << i))
			return (i);
	}
	return (0);
}

int	Fixed::toFloatSetExp(int idxFirstBit, int *bitrepr) const
{
	int	exp;

	exp = idxFirstBit - _nfracts;
	(*bitrepr) |= ((exp + FLOAT_EXP_SHIFT) << FLOAT_BITPOS_EXP);
	return (exp);
}

void	Fixed::toFloatSetNormalMantissa(int val, int shift, int *bitrepr) const
{
	if (shift < 0)
		(*bitrepr) |= (val >> -shift) & FLOAT_MANTISSA_MASK;
	else
		(*bitrepr) |= (val << shift) & FLOAT_MANTISSA_MASK;
}

void	Fixed::toFloatSetSubnormalMantissa(int val, int *bitrepr) const
{
	int	mask;

	mask = val;
	for (int i = 0; i < Fixed::_subnormalOffset; i++)
		mask *= 2;
	mask = mask & FLOAT_MANTISSA_MASK;
	(*bitrepr) |= mask;
}

float	Fixed::toFloat(void) const
{
	int	val;
	int	bitrepr;
	int	i_firstbit;
	int	exp;

	if (_bits == 0)
		return ((float)0.0);
	val = _bits;
	bitrepr = 0;
	toFloatSetSign(&val, &bitrepr);
	i_firstbit = getFirstBitIdx(val);
	exp = toFloatSetExp(i_firstbit, &bitrepr);
	if (exp > -FLOAT_EXP_SHIFT)
		toFloatSetNormalMantissa(val, FLOAT_BITPOS_EXP - i_firstbit, &bitrepr);
	else if (Fixed::_subnormalOffset <= INT_NBITS)
		toFloatSetSubnormalMantissa(val, &bitrepr);
	return (*((float *)(&bitrepr)));
}

int	Fixed::toInt(void) const
{
	return (_bits >> Fixed::_nfracts);
}

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
