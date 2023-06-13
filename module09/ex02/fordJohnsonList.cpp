#include "GroupIterator.hpp"
#include "debugCout.hpp"
#include "getJacobsthalDiff.hpp"
#include <list>
#include <vector>

void fordJohnsonMergeBuildChainPends(GroupIterator &begin,
									 GroupIterator &end,
									 bool hasStraggler,
									 std::list<GroupIterator> &s,
									 std::vector<std::list<GroupIterator>::iterator> &pend)
{
	s.push_back(begin);
	s.push_back(begin + 1);

	GroupIterator endWithoutStraggler = hasStraggler ? end - 1 : end;
	for (GroupIterator it = begin + 2; it != endWithoutStraggler; it += 2)
	{
		std::list<GroupIterator>::iterator next = s.insert(s.end(), it + 1);
		pend.push_back(next);
	}

	DEBUGCOUTLN(__func__ << ": s : " << s);

	if (hasStraggler)
		pend.push_back(s.end());

	DEBUGCOUTLN(__func__ << ": pend: " << pendVectorToString(pend, s));
}

void fordJohnsonInsertJacobsthalDiff(GroupIterator &b_search_start,
									 std::list<GroupIterator> &s,
									 size_t &pend_i,
									 std::vector<std::list<GroupIterator>::iterator> &pend)
{
	int k = 0;
	while (true)
	{
		size_t dist = getJacobsthalDiff(k);
		DEBUGCOUTLN(__func__ << ": Jacobsthal diff " << dist);
		if (dist > pend.size() - pend_i)
			break;

		GroupIterator b_inserted = b_search_start + dist * 2;
		if (!b_inserted.valid())
			break;

		size_t pend_bound = pend_i + dist;
		while (true)
		{
			pend_bound -= 1;
			b_inserted -= 2;
			if (!b_inserted.valid())
				break;

			DEBUGCOUT(__func__ << ": find insertion point of " << b_inserted << " (idx " << b_inserted.getIdx() << ")");

			std::list<GroupIterator>::iterator insertion_point
				= std::upper_bound(s.begin(), pend[pend_bound], b_inserted, compareGroupIterator);
			DEBUGCOUTLN(": insert before " << *insertion_point);

			s.insert(insertion_point, b_inserted);
			if (pend_bound == pend_i)
				break;
		}
		b_search_start += dist * 2;
		if (!b_search_start.valid())
			break;
		pend_i += dist;
		k++;
	}
}

void fordJohnsonInsert(GroupIterator &begin,
					   std::list<GroupIterator> &s,
					   std::vector<std::list<GroupIterator>::iterator> &pend)
{
	GroupIterator b_cursor = begin + 2;
	size_t pend_i = 0;

	fordJohnsonInsertJacobsthalDiff(b_cursor, s, pend_i, pend);

	while (pend_i < pend.size())
	{
		DEBUGCOUT(__func__ << ": find insertion point of " << b_cursor << " (idx " << b_cursor.getIdx() << ")");

		std::list<GroupIterator>::iterator insertion_point
			= std::upper_bound(s.begin(), pend[pend_i], b_cursor, compareGroupIterator);
		DEBUGCOUTLN(": insert before " << pendToString(insertion_point, s));

		s.insert(insertion_point, b_cursor);
		b_cursor += 2;
		if (!b_cursor.valid())
			break;
		pend_i++;
	}

	DEBUGCOUTLN(__func__ << ": result s: " << s);
}

void groupCopy(std::list<int> &l, std::list<GroupIterator> &s)
{
	std::list<int> cache;

	for (std::list<GroupIterator>::iterator group = s.begin(); group != s.end(); ++group)
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

void fordJohnsonMerge(std::list<int> &l, GroupIterator &begin, GroupIterator &end, bool hasStraggler)
{
	DEBUGCOUT(__func__ << ": begin with span " << begin.getSpan() << " len " << distance(begin, end) << " ");
	for (GroupIterator it = begin; it != end; ++it)
		DEBUGCOUT(it);
	if (hasStraggler)
		DEBUGCOUT(" with straggler");
	DEBUGCOUT(std::endl);

	std::list<GroupIterator> s;
	std::vector<std::list<GroupIterator>::iterator> pend;
	fordJohnsonMergeBuildChainPends(begin, end, hasStraggler, s, pend);
	fordJohnsonInsert(begin, s, pend);
	groupCopy(l, s);
}

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

void fordJohnsonSortImpl(std::list<int> &l, ssize_t len, GroupIterator &begin, GroupIterator &end)
{
	ssize_t n_groups = distance(begin, end);
	ssize_t nPairs = n_groups / 2;

	if (n_groups <= 1)
		return;

	bool hasStraggler = false;
	if (n_groups % 2 == 1)
		hasStraggler = true;

	sortEachPairs(begin, nPairs);

	if (nPairs > 1)
	{
		GroupIterator nextBegin(l, len, begin.getIter(), begin.getSpan() * 2);
		GroupIterator nextEnd = nextBegin + nPairs;
		fordJohnsonSortImpl(l, len, nextBegin, nextEnd);
	}

	if (nPairs >= 2 || hasStraggler)
		fordJohnsonMerge(l, begin, end, hasStraggler);
}
