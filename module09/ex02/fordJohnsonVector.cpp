#include "GroupPointer.hpp"
#include "debugCout.hpp"
#include "getJacobsthalDiff.hpp"
#include <list>
#include <vector>

#ifdef DEBUG
#include <sstream>

std::ostream &operator<<(std::ostream &os, std::list<GroupPointer> &lgi)
{
	for (std::list<GroupPointer>::iterator it = lgi.begin(); it != lgi.end(); it++)
		os << (*it);
	return (os);
}

std::string pendVectorToString(std::vector<std::list<GroupPointer>::iterator> &pend, std::list<GroupPointer> &s)
{
	std::stringstream buf;
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (pend[i] == s.end())
			buf << "(before end)";
		else
			buf << "(before " << *(pend[i]) << ")";
	}
	return (buf.str());
}

std::string pendToString(std::list<GroupPointer>::iterator &pend, std::list<GroupPointer> &s)
{
	std::stringstream buf;
	if (pend == s.end())
		buf << "(before end)";
	else
		buf << "(before " << *pend << ")";
	return (buf.str());
}
#endif

void sortEachPairs(GroupPointer begin, ssize_t nPairs)
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

void groupCopy(std::vector<int> &v, std::list<GroupPointer> &s)
{
	std::list<int> cache;

	for (std::list<GroupPointer>::iterator group = s.begin(); group != s.end(); ++group)
	{
		int *valit = (*group).getPtr();
		for (ssize_t i = 0; i < (*group).getSpan(); i++)
		{
			cache.push_back(*valit);
			valit++;
		}
	}

	int *targetptr = &(v[0]);
	for (std::list<int>::iterator cacheit = cache.begin(); cacheit != cache.end(); ++cacheit)
	{
		*targetptr = *cacheit;
		++targetptr;
	}
}

void fordJohnsonMergeBuildChainPends(GroupPointer &begin,
									 GroupPointer &end,
									 bool hasStraggler,
									 std::list<GroupPointer> &s,
									 std::vector<std::list<GroupPointer>::iterator> &pend)
{
	s.push_back(begin);
	s.push_back(begin + 1);

	GroupPointer endWithoutStraggler = hasStraggler ? end - 1 : end;
	for (GroupPointer it = begin + 2; it != endWithoutStraggler; it += 2)
	{
		std::list<GroupPointer>::iterator next = s.insert(s.end(), it + 1);
		pend.push_back(next);
	}

	DEBUGCOUTLN(__func__ << ": s : " << s);

	if (hasStraggler)
		pend.push_back(s.end());

	DEBUGCOUTLN(__func__ << ": pend: " << pendVectorToString(pend, s));
}

void fordJohnsonInsertJacobsthalDiff(GroupPointer &b_search_start,
									 std::list<GroupPointer> &s,
									 size_t &pend_i,
									 std::vector<std::list<GroupPointer>::iterator> &pend)
{
	int k = 0;
	while (true)
	{
		size_t dist = getJacobsthalDiff(k);
		DEBUGCOUTLN(__func__ << ": Jacobsthal diff " << dist);
		if (dist > pend.size() - pend_i)
			break;

		GroupPointer b_inserted = b_search_start + dist * 2;
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

			std::list<GroupPointer>::iterator insertion_point
				= std::upper_bound(s.begin(), pend[pend_bound], b_inserted, compareGroupPointer);
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

void fordJohnsonInsert(GroupPointer &begin,
					   std::list<GroupPointer> &s,
					   std::vector<std::list<GroupPointer>::iterator> &pend)
{
	GroupPointer b_cursor = begin + 2;
	size_t pend_i = 0;

	fordJohnsonInsertJacobsthalDiff(b_cursor, s, pend_i, pend);

	while (pend_i < pend.size())
	{
		DEBUGCOUT(__func__ << ": find insertion point of " << b_cursor << " (idx " << b_cursor.getIdx() << ")");

		std::list<GroupPointer>::iterator insertion_point
			= std::upper_bound(s.begin(), pend[pend_i], b_cursor, compareGroupPointer);
		DEBUGCOUTLN(": insert before " << pendToString(insertion_point, s));

		s.insert(insertion_point, b_cursor);
		b_cursor += 2;
		if (!b_cursor.valid())
			break;
		pend_i++;
	}

	DEBUGCOUTLN(__func__ << ": result s: " << s);
}

void fordJohnsonMerge(std::vector<int> &v, GroupPointer &begin, GroupPointer &end, bool hasStraggler)
{
	DEBUGCOUT(__func__ << ": begin with span " << begin.getSpan() << " len " << distance(begin, end) << " ");
	for (GroupPointer it = begin; it != end; ++it)
		DEBUGCOUT(it);
	if (hasStraggler)
		DEBUGCOUT(" with straggler");
	DEBUGCOUT(std::endl);

	std::list<GroupPointer> s;
	std::vector<std::list<GroupPointer>::iterator> pend;
	fordJohnsonMergeBuildChainPends(begin, end, hasStraggler, s, pend);
	fordJohnsonInsert(begin, s, pend);
	groupCopy(v, s);
}

void fordJohnsonSortImpl(std::vector<int> &v, ssize_t len, GroupPointer &begin, GroupPointer &end)
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
		GroupPointer nextBegin(v, len, begin.getIdx(), begin.getSpan() * 2);
		GroupPointer nextEnd = nextBegin + nPairs;
		fordJohnsonSortImpl(v, len, nextBegin, nextEnd);
	}

	if (nPairs >= 2 || hasStraggler)
		fordJohnsonMerge(v, begin, end, hasStraggler);
}
