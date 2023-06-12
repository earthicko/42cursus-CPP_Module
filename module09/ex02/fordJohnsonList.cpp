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

void groupCopy(std::list<int> &dest, std::list<GroupIterator> &from, ssize_t span)
{
	std::list<GroupIterator>::iterator fromit = from.begin();
	while (fromit != from.end())
	{
		std::list<int>::iterator valit = (*fromit).getIter();
		for (ssize_t i = 0; i < span; i++)
		{
			dest.push_back(*valit);
			valit++;
		}
		++fromit;
	}
}

void groupCopy(GroupIterator destbegin, GroupIterator destend, std::list<int> &from, ssize_t span)
{
	GroupIterator fromit(from.begin(), span);
	GroupIterator destit = destbegin;
	while (destit != destend)
	{
		destit.copyFrom(fromit);
		++fromit;
		++destit;
	}
}

void fordJohnsonMergeBuildChainPends(GroupIterator &begin,
									 GroupIterator &end,
									 bool hasStraggler,
									 std::list<GroupIterator> &chain,
									 std::vector<std::list<GroupIterator>::iterator> &pend)
{
	typedef GroupIterator giter;

	chain.push_back(begin);
	chain.push_back(begin + 1);

	giter endWithoutStraggler = hasStraggler ? end - 1 : end;
	for (giter it = begin + 2; it != endWithoutStraggler; it += 2)
	{
		std::list<giter>::iterator next = chain.insert(chain.end(), it + 1);
		pend.push_back(next);
	}

	DEBUGCOUT(__func__ << ": chain : ");
	for (std::list<giter>::iterator it = chain.begin(); it != chain.end(); it++)
		DEBUGCOUT(*it);
	DEBUGCOUT(std::endl);

	if (hasStraggler)
		pend.push_back(chain.end());

	DEBUGCOUT(__func__ << ": pend: ");
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (pend[i] == chain.end())
			DEBUGCOUT("(end)");
		else
			DEBUGCOUT(*(pend[i]));
	}
	DEBUGCOUT(std::endl);
}

void fordJohnsonInsert(GroupIterator &begin,
					   std::list<GroupIterator> &chain,
					   std::vector<std::list<GroupIterator>::iterator> &pend)
{
	typedef GroupIterator giter;

	giter current_it = begin + 2;
	size_t curr_pend_idx = 0;

	for (int k = 0;; ++k)
	{
		size_t dist = getJacobsthalDiff(k);
		DEBUGCOUT(__func__ << ": dist " << dist << std::endl);
		if (dist > pend.size() - curr_pend_idx)
		{
			DEBUGCOUT(__func__ << ": dist > pend.size() - curr_pend_idx (" << pend.size() - curr_pend_idx << "), break"
							   << std::endl);
			break;
		}
		giter it = current_it + dist * 2;
		size_t pe = curr_pend_idx + dist;
		DEBUGCOUT(__func__ << ": current_it " << current_it << " it " << it << " curr_pend_idx " << curr_pend_idx
						   << " pe " << pe << std::endl);
		while (true)
		{
			--pe;
			it -= 2;
			DEBUGCOUT(__func__ << ": it " << it << " pe " << pe << std::endl);
			std::list<giter>::iterator insertion_point
				= std::upper_bound(chain.begin(), pend[pe], it, compareGroupIterator);
			DEBUGCOUT(__func__ << ": insert point " << *insertion_point << " insert " << it << std::endl);
			chain.insert(insertion_point, it);
			if (pe == curr_pend_idx)
			{
				DEBUGCOUT(__func__ << ": pe == curr_pend_idx, break" << std::endl);
				break;
			}
		}
		current_it += dist * 2;
		curr_pend_idx += dist;
	}

	while (curr_pend_idx < pend.size())
	{
		std::list<giter>::iterator insertion_point
			= std::upper_bound(chain.begin(), pend[curr_pend_idx], current_it, compareGroupIterator);
		if (insertion_point != chain.end())
			DEBUGCOUT(": pend not empty, insert point " << *insertion_point << " insert " << current_it << std::endl);
		else
			DEBUGCOUT(": pend not empty, insert point (end) insert " << current_it << std::endl);
		chain.insert(insertion_point, current_it);
		current_it += 2;
		curr_pend_idx++;
		DEBUGCOUT(__func__ << ": current_it " << current_it << " curr_pend_idx " << curr_pend_idx << std::endl);
	}

	DEBUGCOUT(__func__ << ": result chain : ");
	for (std::list<GroupIterator>::iterator it = chain.begin(); it != chain.end(); it++)
		DEBUGCOUT(*it);
	DEBUGCOUT(std::endl);
}

void fordJohnsonMerge(GroupIterator begin, GroupIterator end, bool hasStraggler)
{
	typedef GroupIterator giter;

	DEBUGCOUT(__func__ << ": begin with span " << begin.getSpan() << " len " << distance(begin, end) << " ");
	for (giter it = begin; it != end; ++it)
		DEBUGCOUT(it);
	if (hasStraggler)
		DEBUGCOUT(" with straggler");
	DEBUGCOUT(std::endl);

	std::list<giter> chain;
	std::vector<std::list<giter>::iterator> pend;
	fordJohnsonMergeBuildChainPends(begin, end, hasStraggler, chain, pend);

	fordJohnsonInsert(begin, chain, pend);

	std::list<int> cache;
	groupCopy(cache, chain, begin.getSpan());
	groupCopy(begin, end, cache, begin.getSpan());
}

void fordJohnsonSortImpl(GroupIterator begin, GroupIterator end)
{
	ssize_t len = distance(begin, end);
	ssize_t nPairs = len / 2;

	if (len <= 1)
	{
		DEBUGCOUT(__func__ << ": return because len <= 1" << std::endl);
		return;
	}

	DEBUGCOUT(__func__ << ": begin with span " << begin.getSpan() << " len " << len << " ");
	for (GroupIterator it = begin; it != end; ++it)
		DEBUGCOUT(it);
	DEBUGCOUT(std::endl);

	bool hasStraggler = false;
	if (len % 2 == 1)
	{
		hasStraggler = true;
		DEBUGCOUT(__func__ << ": has straggler" << std::endl);
	}

	sortEachPairs(begin, nPairs);
	DEBUGCOUT(__func__ << ": after sortEachPairs: ");
	for (GroupIterator it = begin; it != end; ++it)
		DEBUGCOUT(it);
	DEBUGCOUT(std::endl);

	if (nPairs > 1)
	{
		DEBUGCOUT(__func__ << ": begin recursion" << std::endl);

		GroupIterator nextBegin(begin.getIter(), begin.getSpan() * 2);
		GroupIterator nextEnd = nextBegin + nPairs;
		fordJohnsonSortImpl(nextBegin, nextEnd);
		DEBUGCOUT(__func__ << ": after recursion: ");
		for (GroupIterator it = begin; it != end; ++it)
			DEBUGCOUT(it);
		DEBUGCOUT(std::endl);
	}

	if (nPairs >= 2 || hasStraggler)
	{
		fordJohnsonMerge(begin, end, hasStraggler);
		DEBUGCOUT(__func__ << ": after merge: ");
		for (GroupIterator it = begin; it != end; ++it)
			DEBUGCOUT(it);
		DEBUGCOUT(std::endl);
	}
}
