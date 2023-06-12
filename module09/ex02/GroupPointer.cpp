#include "GroupPointer.hpp"

GroupPointer::GroupPointer(std::vector<int> &v, size_t idx, size_t span)
	: _v(v)
	, _begin(&v[0] + idx)
	, _comp(&v[0] + idx + span)
	, _span(span)
{
}

GroupPointer::GroupPointer(const GroupPointer &orig)
	: _v(orig._v)
	, _begin(orig._begin)
	, _comp(orig._comp)
	, _span(orig._span)
{
}

GroupPointer &GroupPointer::operator++(void)
{
	_begin += _span;
	_comp += _span;
	return (*this);
}

GroupPointer &GroupPointer::operator--(void)
{
	_begin -= _span;
	_comp -= _span;
	return (*this);
}

const int &GroupPointer::operator*(void) const
{
	return (*_comp);
}

void GroupPointer::advance(size_t amount)
{
	_begin += amount;
	_comp += amount;
}

std::vector<int> &GroupPointer::getVector(void)
{
	return (_v);
}

int *GroupPointer::getPtr(void) const
{
	return (_comp);
}

const size_t &GroupPointer::getSpan(void) const
{
	return (_span);
}

void GroupPointer::swap(const GroupPointer &other) const
{
	if (_span != other._span)
		throw(std::runtime_error(""));

	int *lhs = _begin;
	int *rhs = other._begin;
	for (size_t i = 0; i < _span; i++)
	{
		int temp = *lhs;
		*lhs = *rhs;
		*rhs = temp;
		++lhs;
		++rhs;
	}
}

void GroupPointer::copyFrom(const GroupPointer &other) const
{
	if (_span != other._span)
		throw(std::runtime_error(""));

	int *lhs = _begin;
	int *rhs = other._begin;
	for (size_t i = 0; i < _span; i++)
	{
		*lhs = *rhs;
		lhs++;
		rhs++;
	}
}

void GroupPointer::insertToStream(std::ostream &os) const
{
	os << "[";
	int *it = _begin;
	while (true)
	{
		os << *it;
		if (it == _comp)
			break;
		os << ", ";
		it++;
	}
	os << "]";
}

bool operator==(const GroupPointer &lhs, const GroupPointer &rhs)
{
	return (lhs.getPtr() == rhs.getPtr() && lhs.getSpan() == rhs.getSpan());
}

bool operator!=(const GroupPointer &lhs, const GroupPointer &rhs)
{
	return (!(lhs == rhs));
}

GroupPointer &operator+=(GroupPointer &it, size_t amount)
{
	it.advance(amount);
	return (it);
}

GroupPointer &operator-=(GroupPointer &it, size_t amount)
{
	it.advance(amount);
	return (it);
}

GroupPointer operator+(const GroupPointer &it, size_t amount)
{
	GroupPointer result = it;
	result += amount;
	return (result);
}

GroupPointer operator-(const GroupPointer &it, size_t amount)
{
	GroupPointer result = it;
	result -= amount;
	return (result);
}

size_t distance(const GroupPointer &lhs, const GroupPointer &rhs)
{
	return (rhs.getPtr() - lhs.getPtr());
}

std::ostream &operator<<(std::ostream &os, const GroupPointer &it)
{
	it.insertToStream(os);
	return (os);
}

bool compareGroupPointer(const GroupPointer &lhs, const GroupPointer &rhs)
{
	return (*lhs < *rhs);
}
