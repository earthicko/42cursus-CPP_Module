#include "PmergeMe.hpp"
#include "debugCout.hpp"
#include "fordJohnsonSort.hpp"
#include <list>
#include <vector>

void fordJohnsonSort(std::list<int> &l)
{
	ssize_t len = l.size();

	GroupIterator begin(l, len, l.begin(), 1);
	GroupIterator end(l, len, l.end(), 1);

	fordJohnsonSortImpl(l, len, begin, end);
}

void fordJohnsonSort(std::vector<int> &v)
{
	ssize_t len = v.size();

	GroupPointer begin(v, len, 0, 1);
	GroupPointer end(v, len, v.size(), 1);

	fordJohnsonSortImpl(v, len, begin, end);
}
