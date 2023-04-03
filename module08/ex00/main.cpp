#include <vector>
#include <iostream>
#include "easyfind.hpp"

template <typename contT>
void	tryFindElemFrom(contT cont, int elem)
{
	bool	found;

	found = false;
	try
	{
		easyfind(cont, elem);
		found = true;
	}
	catch (const std::exception &e)
	{
		std::cout << "Target " << elem << " not found.\n";
	}
	if (found)
		std::cout << "Found " << elem << "\n";
}

template <typename T>
void	testContainer(T cont)
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
