#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int>			intarr(64);
	Array<long long>	llarr(64);

	for (t_uint i = 0; i < intarr.size(); i++)
		intarr[i] = (long long)1 << i;
	for (t_uint i = 0; i < intarr.size(); i++)
		std::cout << intarr[i] << ", ";
	std::cout << "\n";
	for (t_uint i = 0; i < llarr.size(); i++)
		llarr[i] = (long long)1 << i;
	for (t_uint i = 0; i < llarr.size(); i++)
		std::cout << llarr[i] << ", ";
	return (0);
}
