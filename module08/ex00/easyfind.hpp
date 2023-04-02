#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
int	easyfind(T container, int target)
{
	typename T::iterator	iter;

	iter = container.begin();
	while (iter != container.end())
	{
		if (*iter == target)
			return (*iter);
		iter++;
	}
	throw (std::runtime_error("target not found\n"));
}

#endif
