#include "GroupPointer.hpp"

GroupPointer::GroupPointer(std::vector<int> &v, ssize_t len, ssize_t idx, ssize_t span)
	: _v(v)
	, _idx(idx)
	, _len(len)
	, _begin(&v[0] + idx)
	, _comp(&v[0] + (idx + span - 1))
	, _span(span)
{
}

GroupPointer::GroupPointer(const GroupPointer &orig)
	: _v(orig._v)
	, _idx(orig._idx)
	, _len(orig._len)
	, _begin(orig._begin)
	, _comp(orig._comp)
	, _span(orig._span)
{
}

bool GroupPointer::valid(void) const
{
	return (0 <= _idx && _idx <= _len && _span > 0);
}

GroupPointer &GroupPointer::operator++(void)
{
	_idx += _span;
	_begin += _span;
	_comp += _span;
	return (*this);
}

GroupPointer &GroupPointer::operator--(void)
{
	_idx -= _span;
	_begin -= _span;
	_comp -= _span;
	return (*this);
}

const int &GroupPointer::operator*(void) const
{
	return (*_comp);
}

void GroupPointer::advance(ssize_t amount)
{
	_idx += (amount * _span);
	_begin += (amount * _span);
	_comp += (amount * _span);
}

int *GroupPointer::getPtr(void) const
{
	return (_begin);
}

const ssize_t &GroupPointer::getIdx(void) const
{
	return (_idx);
}

const ssize_t &GroupPointer::getSpan(void) const
{
	return (_span);
}

void GroupPointer::swap(const GroupPointer &other) const
{
	if (_span != other._span)
		throw(std::runtime_error(""));

	int *lhs = _begin;
	int *rhs = other._begin;
	for (ssize_t i = 0; i < _span; i++)
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
	for (ssize_t i = 0; i < _span; i++)
	{
		*lhs = *rhs;
		++lhs;
		++rhs;
	}
}

void GroupPointer::insertToStream(std::ostream &os) const
{
	os << "[";
	for (ssize_t i = 0; i < _span - 1; i++)
		os << ". ";
	ssize_t compidx = _idx + _span - 1;
	if (0 <= compidx && compidx < _len)
		os << *_comp;
	else
		os << "e";
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

GroupPointer &operator+=(GroupPointer &it, ssize_t amount)
{
	it.advance(amount);
	return (it);
}

GroupPointer &operator-=(GroupPointer &it, ssize_t amount)
{
	it.advance(-amount);
	return (it);
}

GroupPointer operator+(const GroupPointer &it, ssize_t amount)
{
	GroupPointer result(it);
	result += amount;
	return (result);
}

GroupPointer operator-(const GroupPointer &it, ssize_t amount)
{
	GroupPointer result(it);
	result -= amount;
	return (result);
}

ssize_t distance(const GroupPointer &lhs, const GroupPointer &rhs)
{
	if (lhs.getSpan() != rhs.getSpan())
		throw(std::runtime_error(""));
	return ((rhs.getPtr() - lhs.getPtr()) / lhs.getSpan());
}

std::ostream &operator<<(std::ostream &os, const GroupPointer &it)
{
	it.insertToStream(os);
	return (os);
}

bool compareGroupPointer(const GroupPointer &lhs, const GroupPointer &rhs)
{
	if (lhs.getSpan() != rhs.getSpan())
		throw(std::runtime_error(""));
	return (*lhs < *rhs);
}
