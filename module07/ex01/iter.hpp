#ifndef ITER_HPP
#define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename arrayElemT, typename funcT>
void	iter(arrayElemT *arr, size_t len, funcT func)
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

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

#endif
