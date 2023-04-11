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

#endif
