#include "Fixed.hpp"
#include "sizedef.hpp"

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

Fixed	Fixed::getE(void)
{
	Fixed	e;

	e.setRawBits(1);
	return (e);
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
