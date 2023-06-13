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

	DEBUGCOUT(__func__ << ": before sort: ");
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		DEBUGCOUT(*it << " ");
	DEBUGCOUT(std::endl);

	fordJohnsonSortImpl(l, len, begin, end);

	DEBUGCOUT(__func__ << ": after sort: ");
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
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

	fordJohnsonSortImpl(v, begin, end);

	DEBUGCOUT(__func__ << ": after sort: ");
	for (size_t i = 0; i < v.size(); i++)
		DEBUGCOUT(v[i] << " ");
	DEBUGCOUT(std::endl);
}
