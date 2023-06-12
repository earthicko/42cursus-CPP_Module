#include "PmergeMe.hpp"
#include "debugCout.hpp"
#include "fordJohnsonSort.hpp"
#include <list>
#include <vector>

void fordJohnsonSort(std::list<int> &v)
{
	GroupIterator begin(v.begin(), 1);
	GroupIterator end(v.end(), 1);

	DEBUGCOUT(__func__ << ": before sort: ");
	for (std::list<int>::iterator it = v.begin(); it != v.end(); it++)
		DEBUGCOUT(*it << " ");
	DEBUGCOUT(std::endl);

	fordJohnsonSortImpl(begin, end);

	DEBUGCOUT(__func__ << ": after sort: ");
	for (std::list<int>::iterator it = v.begin(); it != v.end(); it++)
		DEBUGCOUT(*it << " ");
	DEBUGCOUT(std::endl);
}

void fordJohnsonSort(std::vector<int> &v)
{
	GroupPointer begin(v, 0, 1);
	GroupPointer end(v, v.size(), 1);

	DEBUGCOUT(__func__ << ": before sort: ");
	for (size_t i = 0; i < v.size(); i++)
		DEBUGCOUT(v[i] << " ");
	DEBUGCOUT(std::endl);

	fordJohnsonSortImpl(begin, end);

	DEBUGCOUT(__func__ << ": after sort: ");
	for (size_t i = 0; i < v.size(); i++)
		DEBUGCOUT(v[i] << " ");
	DEBUGCOUT(std::endl);
}
