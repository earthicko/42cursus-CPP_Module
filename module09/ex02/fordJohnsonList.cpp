#include "GroupIterator.hpp"
#include "debugCout.hpp"
#include "getJacobsthalDiff.hpp"
#include <list>
#include <vector>

void sortEachPairs(GroupIterator begin, ssize_t nPairs)
{
	while (nPairs)
	{
		GroupIterator next = begin + 1;
		if (*begin > *next)
			begin.swap(next);
		begin += 2;
		--nPairs;
	}
}

void groupCopy(std::list<int> &l, std::list<GroupIterator> &chain)
{
	std::list<int> cache;

	for (std::list<GroupIterator>::iterator group = chain.begin(); group != chain.end(); ++group)
	{
		std::list<int>::iterator valit = (*group).getIter();
		for (ssize_t i = 0; i < (*group).getSpan(); i++)
		{
			cache.push_back(*valit);
			valit++;
		}
	}

	std::list<int>::iterator targetit = l.begin();
	for (std::list<int>::iterator cacheit = cache.begin(); cacheit != cache.end(); ++cacheit)
	{
		*targetit = *cacheit;
		++targetit;
	}
}

void fordJohnsonMergeBuildChainPends(GroupIterator &begin,
									 GroupIterator &end,
									 bool hasStraggler,
									 std::list<GroupIterator> &chain,
									 std::vector<std::list<GroupIterator>::iterator> &pend)
{
	chain.push_back(begin);
	chain.push_back(begin + 1);

	GroupIterator endWithoutStraggler = hasStraggler ? end - 1 : end;
	for (GroupIterator it = begin + 2; it != endWithoutStraggler; it += 2)
	{
		std::list<GroupIterator>::iterator next = chain.insert(chain.end(), it + 1);
		pend.push_back(next);
	}

	DEBUGCOUT(__func__ << ": chain : ");
	for (std::list<GroupIterator>::iterator it = chain.begin(); it != chain.end(); it++)
		DEBUGCOUT(*it);
	DEBUGCOUT(std::endl);

	if (hasStraggler)
		pend.push_back(chain.end());

	DEBUGCOUT(__func__ << ": pend: ");
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (pend[i] == chain.end())
			DEBUGCOUT("(before end)");
		else
			DEBUGCOUT("(before " << *(pend[i]) << ")");
	}
	DEBUGCOUT(std::endl);
}

void fordJohnsonInsertJacobsthalDiff(GroupIterator &b_search_start,
									 std::list<GroupIterator> &chain,
									 size_t &pend_i,
									 std::vector<std::list<GroupIterator>::iterator> &pend)
{
	int k = 0;
	while (true)
	{
		size_t dist = getJacobsthalDiff(k);
		DEBUGCOUTLN(__func__ << ": getJacobsthalDiff " << dist);
		if (dist > pend.size() - pend_i)
		{
			DEBUGCOUTLN(__func__ << ": dist > pend.size() - pend_i (" << pend.size() - pend_i << "), break");
			break;
		}
		GroupIterator b_inserted = b_search_start + dist * 2;
		if (!b_inserted.valid())
		{
			DEBUGCOUTLN(__func__ << ": b_inserted out of bound");
			break;
		}
		size_t pend_bound = pend_i + dist;
		DEBUGCOUTLN(__func__ << ": b_search_start " << b_search_start << " b_inserted " << b_inserted << " pend_i "
							 << pend_i << " pend_bound " << pend_bound);
		while (true)
		{
			--pend_bound;
			b_inserted -= 2;
			if (!b_inserted.valid())
			{
				DEBUGCOUTLN(__func__ << ": b_inserted out of bound");
				break;
			}
			DEBUGCOUTLN(__func__ << ": b_inserted " << b_inserted << " pend_bound " << pend_bound);

			DEBUGCOUT(__func__ << ": upper_bound " << b_inserted << " from " << *(chain.begin()) << " to ");
			if (pend[pend_bound] == chain.end())
				DEBUGCOUTLN(" to (before end)");
			else
				DEBUGCOUTLN(" to (before " << *(pend[pend_bound]) << ")");

			std::list<GroupIterator>::iterator insertion_point
				= std::upper_bound(chain.begin(), pend[pend_bound], b_inserted, compareGroupIterator);
			DEBUGCOUTLN(__func__ << ": insertion_point " << *insertion_point << " b_inserted " << b_inserted);
			chain.insert(insertion_point, b_inserted);
			if (pend_bound == pend_i)
			{
				DEBUGCOUTLN(__func__ << ": pend_bound == pend_i, break");
				break;
			}
		}
		b_search_start += dist * 2;
		if (!b_search_start.valid())
		{
			DEBUGCOUTLN(__func__ << ": b_search_start out of bound");
			break;
		}
		pend_i += dist;
		k++;
	}
}

void fordJohnsonInsert(GroupIterator &begin,
					   std::list<GroupIterator> &chain,
					   std::vector<std::list<GroupIterator>::iterator> &pend)
{
	GroupIterator b_cursor = begin + 2;
	size_t pend_i = 0;

	fordJohnsonInsertJacobsthalDiff(b_cursor, chain, pend_i, pend);

	while (pend_i < pend.size())
	{
		DEBUGCOUT(__func__ << ": pend not empty, upper_bound " << b_cursor << " from " << *(chain.begin()) << " to ");
		if (pend[pend_i] == chain.end())
			DEBUGCOUTLN(" to (before end)");
		else
			DEBUGCOUTLN(" to (before " << *(pend[pend_i]) << ")");
		std::list<GroupIterator>::iterator insertion_point
			= std::upper_bound(chain.begin(), pend[pend_i], b_cursor, compareGroupIterator);
		if (insertion_point != chain.end())
			DEBUGCOUTLN(__func__ << ": insertion_point " << *insertion_point << " b_cursor " << b_cursor);
		else
			DEBUGCOUTLN(__func__ << ": insertion_point (end) b_cursor " << b_cursor);
		chain.insert(insertion_point, b_cursor);
		b_cursor += 2;
		if (!b_cursor.valid())
		{
			DEBUGCOUTLN(__func__ << ": b_cursor out of bound");
			break;
		}
		pend_i++;
		DEBUGCOUTLN(__func__ << ": b_cursor " << b_cursor << " pend_i " << pend_i);
	}

	DEBUGCOUT(__func__ << ": result chain : ");
	for (std::list<GroupIterator>::iterator it = chain.begin(); it != chain.end(); it++)
		DEBUGCOUT(*it);
	DEBUGCOUT(std::endl);
}

void fordJohnsonMerge(std::list<int> &l, GroupIterator &begin, GroupIterator &end, bool hasStraggler)
{
	DEBUGCOUT(__func__ << ": begin with span " << begin.getSpan() << " len " << distance(begin, end) << " ");
	for (GroupIterator it = begin; it != end; ++it)
		DEBUGCOUT(it);
	if (hasStraggler)
		DEBUGCOUT(" with straggler");
	DEBUGCOUT(std::endl);

	std::list<GroupIterator> chain;
	std::vector<std::list<GroupIterator>::iterator> pend;
	fordJohnsonMergeBuildChainPends(begin, end, hasStraggler, chain, pend);
	fordJohnsonInsert(begin, chain, pend);
	groupCopy(l, chain);
}

void fordJohnsonSortImpl(std::list<int> &l, ssize_t len, GroupIterator &begin, GroupIterator &end)
{
	ssize_t n_groups = distance(begin, end);
	ssize_t nPairs = n_groups / 2;

	if (n_groups <= 1)
	{
		DEBUGCOUTLN(__func__ << ": return because n_groups <= 1");
		return;
	}

	DEBUGCOUT(__func__ << ": begin with span " << begin.getSpan() << " n_groups " << n_groups << " ");
	for (GroupIterator it = begin; it != end; ++it)
		DEBUGCOUT(it);
	DEBUGCOUT(std::endl);

	bool hasStraggler = false;
	if (n_groups % 2 == 1)
	{
		hasStraggler = true;
		DEBUGCOUTLN(__func__ << ": has straggler");
	}

	sortEachPairs(begin, nPairs);
	DEBUGCOUT(__func__ << ": after sortEachPairs: ");
	for (GroupIterator it = begin; it != end; ++it)
		DEBUGCOUT(it);
	DEBUGCOUT(std::endl);

	if (nPairs > 1)
	{
		DEBUGCOUTLN(__func__ << ": begin recursion");

		GroupIterator nextBegin(l, len, begin.getIter(), begin.getSpan() * 2);
		GroupIterator nextEnd = nextBegin + nPairs;
		fordJohnsonSortImpl(l, len, nextBegin, nextEnd);
		DEBUGCOUT(__func__ << ": after recursion: ");
		for (GroupIterator it = begin; it != end; ++it)
			DEBUGCOUT(it);
		DEBUGCOUT(std::endl);
	}

	if (nPairs >= 2 || hasStraggler)
	{
		fordJohnsonMerge(l, begin, end, hasStraggler);
		DEBUGCOUT(__func__ << ": after merge: ");
		for (GroupIterator it = begin; it != end; ++it)
			DEBUGCOUT(it);
		DEBUGCOUT(std::endl);
	}
}
