#include <iostream>
#include <limits.h>
#include "Fixed.hpp"
#include "bitUtils.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	/*
	prettyPrintBits((float)1.0);
	prettyPrintBits((float)0.5);
	prettyPrintBits((float)0.25);
	prettyPrintBits((float)0.125);

	prettyPrintBits((float)2.0);
	prettyPrintBits((float)4.0);
	prettyPrintBits((float)8.0);
	prettyPrintBits((float)16.0);

	prettyPrintBits((float)1.5);
	prettyPrintBits((float)2.5);
	prettyPrintBits((float)4.5);

	prettyPrintBits((float)1.25);
	prettyPrintBits((float)2.25);
	prettyPrintBits((float)4.25);

	int	bits0[32] = {0, 0, 0, 0, 0, 0, 0, 0, 
					0, 1, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0};
	float subnormal0 = composeFloat(bits0);
	prettyPrintBits(subnormal0);

	int	bits1[32] = {0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 1, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0};
	float subnormal1 = composeFloat(bits1);
	prettyPrintBits(subnormal1);

	int	bits2[32] = {0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 1, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0};
	float subnormal2 = composeFloat(bits2);
	prettyPrintBits(subnormal2);

	int	bits3[32] = {0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 0, 
					0, 0, 0, 0, 0, 0, 0, 1};
	float subnormal3 = composeFloat(bits3);
	prettyPrintBits(subnormal3);

	int	bits4[32] = {0, 1, 1, 1, 1, 1, 1, 1, 
					0, 1, 1, 1, 1, 1, 1, 1, 
					1, 1, 1, 1, 1, 1, 1, 1, 
					1, 1, 1, 1, 1, 1, 1, 1};
	float subnormal4 = composeFloat(bits4);
	prettyPrintBits(subnormal4);

	std::cout << __FLT_MAX__ << std::endl;
	*/

	a = Fixed((float)1.0);
	b = Fixed((float)0.5);
	c = Fixed((float)0.25);
	prettyPrintBits(a.toFloat());
	prettyPrintBits(b.toFloat());
	prettyPrintBits(c.toFloat());

	a = Fixed((float)2.0);
	b = Fixed((float)4.5);
	c = Fixed((float)8.25);
	prettyPrintBits(a.toFloat());
	prettyPrintBits(b.toFloat());
	prettyPrintBits(c.toFloat());

	a = Fixed((float)-2.0);
	b = Fixed((float)-4.5);
	c = Fixed((float)-8.25);
	prettyPrintBits(a.toFloat());
	prettyPrintBits(b.toFloat());
	prettyPrintBits(c.toFloat());

	a = Fixed((int)-21);
	b = Fixed((int)57);
	c = Fixed((int)70002666);
	prettyPrintBits(a.toFloat());
	prettyPrintBits(b.toFloat());
	prettyPrintBits(c.toFloat());

	return 0;
}
