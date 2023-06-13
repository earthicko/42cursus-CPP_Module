#include "GroupIterator.hpp"

GroupIterator::GroupIterator(std::list<int> &l, ssize_t len, _iterator it, ssize_t span)
	: _l(l)
	, _len(len)
	, _begin(it)
	, _span(span)
{
	_idx = std::distance(l.begin(), _begin);
	_comp = _begin;
	std::advance(_comp, span - 1);
}

GroupIterator::GroupIterator(const GroupIterator &orig)
	: _l(orig._l)
	, _idx(orig._idx)
	, _len(orig._len)
	, _begin(orig._begin)
	, _comp(orig._comp)
	, _span(orig._span)
{
}

bool GroupIterator::valid(void)
{
	return (0 <= _idx && _idx <= _len && _span > 0);
}

GroupIterator &GroupIterator::operator++(void)
{
	_idx += _span;
	std::advance(_begin, _span);
	std::advance(_comp, _span);
	return (*this);
}

GroupIterator &GroupIterator::operator--(void)
{
	_idx -= _span;
	std::advance(_begin, -_span);
	std::advance(_comp, -_span);
	return (*this);
}

const int &GroupIterator::operator*(void) const
{
	return (*_comp);
}

const std::list<int>::iterator &GroupIterator::getIter(void) const
{
	return (_begin);
}

const ssize_t &GroupIterator::getIdx(void) const
{
	return (_idx);
}

const ssize_t &GroupIterator::getSpan(void) const
{
	return (_span);
}

void GroupIterator::swap(const GroupIterator &other) const
{
	if (_span != other._span)
		throw(std::runtime_error(""));

	_iterator lhs = _begin;
	_iterator rhs = other._begin;
	for (ssize_t i = 0; i < _span; i++)
	{
		int temp = *lhs;
		*lhs = *rhs;
		*rhs = temp;
		++lhs;
		++rhs;
	}
}

void GroupIterator::copyFrom(const GroupIterator &other) const
{
	if (_span != other._span)
		throw(std::runtime_error(""));

	_iterator lhs = _begin;
	_iterator rhs = other._begin;
	for (ssize_t i = 0; i < _span; i++)
	{
		*lhs = *rhs;
		lhs++;
		rhs++;
	}
}

void GroupIterator::insertToStream(std::ostream &os) const
{
	os << "[";
	for (ssize_t i = 0; i < _span - 1; i++)
		os << ". ";
	os << *_comp;
	os << "]";
}

bool operator==(const GroupIterator &lhs, const GroupIterator &rhs)
{
	return (lhs.getIter() == rhs.getIter() && lhs.getSpan() == rhs.getSpan());
}

bool operator!=(const GroupIterator &lhs, const GroupIterator &rhs)
{
	return (!(lhs == rhs));
}

GroupIterator &operator+=(GroupIterator &it, ssize_t amount)
{
	while (amount > 0)
	{
		++it;
		amount--;
	}
	return (it);
}

GroupIterator &operator-=(GroupIterator &it, ssize_t amount)
{
	while (amount > 0)
	{
		--it;
		amount--;
	}
	return (it);
}

GroupIterator operator+(const GroupIterator &it, ssize_t amount)
{
	GroupIterator result(it);
	result += amount;
	return (result);
}

GroupIterator operator-(const GroupIterator &it, ssize_t amount)
{
	GroupIterator result(it);
	result -= amount;
	return (result);
}

ssize_t distance(const GroupIterator &lhs, const GroupIterator &rhs)
{
	if (lhs.getSpan() != rhs.getSpan())
		throw(std::runtime_error(""));
	GroupIterator tempLhs(lhs);
	ssize_t result = 0;
	while (tempLhs != rhs)
	{
		++tempLhs;
		++result;
	}
	return (result);
}

std::ostream &operator<<(std::ostream &os, const GroupIterator &it)
{
	it.insertToStream(os);
	return (os);
}

bool compareGroupIterator(const GroupIterator &lhs, const GroupIterator &rhs)
{
	if (lhs.getSpan() != rhs.getSpan())
		throw(std::runtime_error(""));
	return (*lhs < *rhs);
}
