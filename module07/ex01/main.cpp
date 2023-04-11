#include "iter.hpp"
#include <iostream>

#define LEN_ARR 10

template <typename arrayElemT>
void	printArr(arrayElemT *arr, size_t len)
{
	std::cout << "{";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i];
		if (i < len - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

template <typename T>
void	doubleElem(T &elem)
{
	elem = 2 * elem;
}

template <typename T>
void	expElem(T &elem)
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
	iter(ints, LEN_ARR, doubleElem<int>);
	std::cout << "\n";
	std::cout << "After doubleElemInt: ";
	printArr(ints, LEN_ARR);
	std::cout << "\n";
	std::cout << "Before doubleElemLong: ";
	printArr(longs, LEN_ARR);
	iter(longs, LEN_ARR, doubleElem<long>);
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
	iter(ints, LEN_ARR, expElem<int>);
	std::cout << "\n";
	std::cout << "After expElemInt: ";
	printArr(ints, LEN_ARR);
	std::cout << "\n";
	std::cout << "Before expElemLong: ";
	printArr(longs, LEN_ARR);
	iter(longs, LEN_ARR, expElem<long>);
	std::cout << "\n";
	std::cout << "After expElemLong: ";
	printArr(longs, LEN_ARR);
	std::cout << "\n";
	return (0);
}
