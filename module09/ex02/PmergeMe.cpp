#include "PmergeMe.hpp"
#include "GroupIterator.hpp"
#include "GroupPointer.hpp"
#include "debugCout.hpp"
#include <list>
#include <vector>

size_t getJacobsthalDiff(size_t idx)
{
	static const size_t cache[] = {2u,
								   2u,
								   6u,
								   10u,
								   22u,
								   42u,
								   86u,
								   170u,
								   342u,
								   682u,
								   1366u,
								   2730u,
								   5462u,
								   10922u,
								   21846u,
								   43690u,
								   87382u,
								   174762u,
								   349526u,
								   699050u,
								   1398102u,
								   2796202u,
								   5592406u,
								   11184810u,
								   22369622u,
								   44739242u,
								   89478486u,
								   178956970u,
								   357913942u,
								   715827882u,
								   1431655766u,
								   2863311530u,
								   5726623062u,
								   11453246122u,
								   22906492246u,
								   45812984490u,
								   91625968982u,
								   183251937962u,
								   366503875926u,
								   733007751850u,
								   1466015503702u,
								   2932031007402u,
								   5864062014806u,
								   11728124029610u,
								   23456248059222u,
								   46912496118442u,
								   93824992236886u,
								   187649984473770u,
								   375299968947542u,
								   750599937895082u,
								   1501199875790165u,
								   3002399751580331u,
								   6004799503160661u,
								   12009599006321322u,
								   24019198012642644u,
								   48038396025285288u,
								   96076792050570576u,
								   192153584101141152u,
								   384307168202282304u,
								   768614336404564608u,
								   1537228672809129216u,
								   3074457345618258432u,
								   6148914691236516864u};
	if (idx >= 64)
		throw(std::runtime_error(""));
	return (cache[idx]);
}

void sortEachPairs(GroupIterator begin, size_t nPairs)
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

void groupCopy(std::list<int> &dest, std::list<GroupIterator> &from, size_t span)
{
	std::list<GroupIterator>::iterator fromit = from.begin();
	while (fromit != from.end())
	{
		std::list<int>::iterator valit = (*fromit).getIter();
		for (size_t i = 0; i < span; i++)
		{
			dest.push_back(*valit);
			valit++;
		}
		++fromit;
	}
}

void groupCopy(GroupIterator destbegin, GroupIterator destend, std::list<int> &from, size_t span)
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
	size_t len = distance(begin, end);
	size_t nPairs = len / 2;

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

void sortEachPairs(GroupPointer begin, size_t nPairs)
{
	while (nPairs)
	{
		GroupPointer next = begin + 1;
		if (*begin > *next)
			begin.swap(next);
		begin += 2;
		--nPairs;
	}
}

void groupCopy(std::vector<int> &dest, std::list<GroupPointer> &from, size_t span)
{
	std::list<GroupPointer>::iterator fromit = from.begin();
	while (fromit != from.end())
	{
		int *valit = (*fromit).getPtr();
		for (size_t i = 0; i < span; i++)
		{
			dest.push_back(*valit);
			valit++;
		}
		++fromit;
	}
}

void groupCopy(GroupPointer destbegin, std::vector<int> &from)
{
	for (size_t i = 0; i < from.size(); i++)
		destbegin.getVector()[i] = from[i];
}

void fordJohnsonMergeBuildChainPends(GroupPointer &begin,
									 GroupPointer &end,
									 bool hasStraggler,
									 std::list<GroupPointer> &chain,
									 std::vector<std::list<GroupPointer>::iterator> &pend)
{
	typedef GroupPointer giter;

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

void fordJohnsonInsert(GroupPointer &begin,
					   std::list<GroupPointer> &chain,
					   std::vector<std::list<GroupPointer>::iterator> &pend)
{
	typedef GroupPointer giter;

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
				= std::upper_bound(chain.begin(), pend[pe], it, compareGroupPointer);
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
			= std::upper_bound(chain.begin(), pend[curr_pend_idx], current_it, compareGroupPointer);
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
	for (std::list<GroupPointer>::iterator it = chain.begin(); it != chain.end(); it++)
		DEBUGCOUT(*it);
	DEBUGCOUT(std::endl);
}

void fordJohnsonMerge(GroupPointer begin, GroupPointer end, bool hasStraggler)
{
	typedef GroupPointer giter;

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

	std::vector<int> cache;
	groupCopy(cache, chain, begin.getSpan());
	groupCopy(begin, cache);
}

void fordJohnsonSortImpl(GroupPointer begin, GroupPointer end)
{
	size_t len = distance(begin, end);
	size_t nPairs = len / 2;

	if (len <= 1)
	{
		DEBUGCOUT(__func__ << ": return because len <= 1" << std::endl);
		return;
	}

	DEBUGCOUT(__func__ << ": begin with span " << begin.getSpan() << " len " << len << " ");
	for (GroupPointer it = begin; it != end; ++it)
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
	for (GroupPointer it = begin; it != end; ++it)
		DEBUGCOUT(it);
	DEBUGCOUT(std::endl);

	if (nPairs > 1)
	{
		DEBUGCOUT(__func__ << ": begin recursion" << std::endl);

		GroupPointer nextBegin(begin.getVector(), 0, begin.getSpan() * 2);
		GroupPointer nextEnd = nextBegin + nPairs;
		fordJohnsonSortImpl(nextBegin, nextEnd);
		DEBUGCOUT(__func__ << ": after recursion: ");
		for (GroupPointer it = begin; it != end; ++it)
			DEBUGCOUT(it);
		DEBUGCOUT(std::endl);
	}

	if (nPairs >= 2 || hasStraggler)
	{
		fordJohnsonMerge(begin, end, hasStraggler);
		DEBUGCOUT(__func__ << ": after merge: ");
		for (GroupPointer it = begin; it != end; ++it)
			DEBUGCOUT(it);
		DEBUGCOUT(std::endl);
	}
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
