#include "iter.hpp"
#include <iostream>

#define LEN_ARR 10

void	doubleElemInt(int &elem)
{
	elem = 2 * elem;
}

void	doubleElemLong(long &elem)
{
	elem = 2 * elem;
}

void	expElemInt(int &elem)
{
	elem = 1 << elem;
}

void	expElemLong(long &elem)
{
	elem = 1 << elem;
}

int	main(void)
{
	int		ints[LEN_ARR];
	long	longs[LEN_ARR];

	for (int i = 0; i < LEN_ARR; i++)
	{
		ints[i] = i;
		longs[i] = i * 2;
	}
	std::cout << "Before doubleElemInt: ";
	printArr(ints, LEN_ARR);
	iter(ints, LEN_ARR, doubleElemInt);
	std::cout << "\n";
	std::cout << "After doubleElemInt: ";
	printArr(ints, LEN_ARR);
	std::cout << "\n";
	std::cout << "Before doubleElemLong: ";
	printArr(longs, LEN_ARR);
	iter(longs, LEN_ARR, doubleElemLong);
	std::cout << "\n";
	std::cout << "After doubleElemLong: ";
	printArr(longs, LEN_ARR);
	std::cout << "\n";
	for (int i = 0; i < LEN_ARR; i++)
	{
		ints[i] = i;
		longs[i] = i * 2;
	}
	std::cout << "Before expElemInt: ";
	printArr(ints, LEN_ARR);
	iter(ints, LEN_ARR, expElemInt);
	std::cout << "\n";
	std::cout << "After expElemInt: ";
	printArr(ints, LEN_ARR);
	std::cout << "\n";
	std::cout << "Before expElemLong: ";
	printArr(longs, LEN_ARR);
	iter(longs, LEN_ARR, expElemLong);
	std::cout << "\n";
	std::cout << "After expElemLong: ";
	printArr(longs, LEN_ARR);
	std::cout << "\n";
	return (0);
}
