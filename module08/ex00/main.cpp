#include <vector>
#include <iostream>
#include "easyfind.hpp"

template <typename T>
void	tryFindElemFrom(T &cont, int elem)
{
	typename T::iterator	iter;
	int						idx;

	iter = easyfind(cont, elem);
	idx = std::distance(cont.begin(), iter);
	idx = iter - cont.begin();
	if (iter != cont.end())
		std::cout << "Target " << *iter << " found at idx [" << idx << "]\n";
	else
		std::cout << "Target " << elem << " not found\n";
}

template <typename T>
void	testContainer(T &cont)
{
	for (int i = 0; i < 10; i++)
		tryFindElemFrom(cont, i);
}

int	main(void)
{
	const int	intArr[] = {1, 2, 4, 8};
	std::vector<int> intV(intArr, intArr + sizeof(intArr) / sizeof(int));

	testContainer(intV);
	return (0);
}
