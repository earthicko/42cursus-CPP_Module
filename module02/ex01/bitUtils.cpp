#include <cstdlib>
#include <cstdio>
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "bitUtils.hpp"
#include "sizedef.h"

std::string	int_to_string(int num)
{
	char buffer[32];

	snprintf(buffer, 32, "%d", num);
	return buffer;
}

static unsigned char	getNthByteFrom(void *ptr, int n)
{
	return (((unsigned char *)ptr)[n]);
}

static int	getNthBitFrom(void *ptr, int n)
{
	int	val;
	
	val = *((int *)ptr);
	if (val & (1 << n))
		return (1);
	else
		return (0);
}

static void	printColumn(std::string column)
{
	if (column.length() > COLUMN_WIDTH)
		column = column.substr(0, COLUMN_WIDTH - 1) + ".";
	std::cout << std::setw(COLUMN_WIDTH) << std::right;
	std::cout << column;
	std::cout << std::resetiosflags(std::ios::right);
	std::cout << std::resetiosflags(std::ios::adjustfield);
}

static void	_printBits(unsigned char val)
{
	unsigned char	divider;

	divider = (1 << (NBITSPERBYTE - 1));
	for (int i = 0; i < NBITSPERBYTE; i++)
	{
		std::cout << COLUMN_DIVIDER;
		printColumn(int_to_string(val / divider));
		val = val % divider;
		divider /= 2;
	}
}

void	printBits(unsigned char val)
{
	_printBits(val);
	std::cout << COLUMN_DIVIDER << std::endl;
}

void	printBits(int val)
{
	if (LITTLEENDIAN)
	{
		for (int i = (int)sizeof(int) - 1; i >= 0; i--)
			_printBits(getNthByteFrom(&val, i));
	}
	else
	{
		for (int i = 0; i < (int)sizeof(int); i++)
			_printBits(getNthByteFrom(&val, i));
	}
	std::cout << COLUMN_DIVIDER << std::endl;
}

void	printBits(float val)
{
	if (LITTLEENDIAN)
	{
		for (int i = (int)sizeof(float) - 1; i >= 0; i--)
			_printBits(getNthByteFrom(&val, i));
	}
	else
	{
		for (int i = 0; i < (int)sizeof(float); i++)
			_printBits(getNthByteFrom(&val, i));
	}
	std::cout << COLUMN_DIVIDER << std::endl;
}

static void	printRange(int s, int e)
{
	for (int i = s; i < e; i++)
	{
		std::cout << COLUMN_DIVIDER;
		printColumn(int_to_string(i));
	}
	std::cout << COLUMN_DIVIDER << std::endl;
}

void	prettyPrintBits(int val)
{
	std::cout << "int " << val << ":" << std::endl;
	printRange(0, NBITSPERBYTE * sizeof(int));
	printBits(val);
}

void	prettyPrintBits(float val)
{
	int			exponent;

	std::cout << "float " << val << ": ";
	std::cout << "sign " << getNthBitFrom(&val, FLOAT_BITPOS_SIGN);
	exponent = (*((int *)(&val)) << 1);
	std::cout << ", exponent 2^" << (int)(getNthByteFrom(&exponent, 3)) - FLOAT_EXP_SHIFT;
	std::cout << " * 1.";
	for (int i = FLOAT_BITPOS_EXP - 1; i >= 0; i--)
		std::cout << getNthBitFrom(&val, i);
	std::cout << "\n| s |128  64  32  16   8   4   2   1|                                                                                           |\n";
	printBits(val);
}

float	composeFloat(int *bits)
{
	int		val;

	val = 0;
	for (int i = 0; i < FLOAT_NBITS; i++)
	{
		if (bits[i])
			val |= (1 << (FLOAT_NBITS - i - 1));
	}
	return (*((float *)&val));
}
