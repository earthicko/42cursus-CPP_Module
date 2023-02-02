#include <cstdlib>
#include <cstdio>
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "bitUtils.hpp"

std::string	int_to_string(int num)
{
	char buffer[32];

	snprintf(buffer, 32, "%d", num);
	return buffer;
}

// little -> true
// big -> false
static bool	isLittleEndian(void)
{
	int	dummy;

	dummy = 1;
	if (((unsigned char *)(&dummy))[0])
		return (true);
	return (false);
}

static unsigned char	getNthByteFrom(void *ptr, int n)
{
	return (((unsigned char *)ptr)[n]);
}

static int	getNbits(void)
{
	int				nBits;
	unsigned char	byte;

	byte = UCHAR_MAX;
	nBits = 0;
	while (byte > 0)
	{
		byte /= 2;
		nBits += 1;
	}
	return (nBits);
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
	static int		nBits;
	unsigned char	divider;

	if (nBits == 0)
		nBits = getNbits();
	divider = (1 << (nBits - 1));
	for (int i = 0; i < nBits; i++)
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
	if (isLittleEndian())
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
	static int	nBits;

	if (nBits == 0)
		nBits = getNbits() * sizeof(int);
	std::cout << "int " << val << ":" << std::endl;
	printRange(0, nBits);
	printBits(val);
}
