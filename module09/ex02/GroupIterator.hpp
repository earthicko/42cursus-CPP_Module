#ifndef GROUPITERATOR_HPP
#define GROUPITERATOR_HPP

#include <iostream>
#include <list>

class GroupIterator
{
  private:
	typedef std::list<int>::iterator _iterator;
	_iterator _begin;
	_iterator _comp;
	size_t _span;

  public:
	GroupIterator(_iterator it, size_t span);
	GroupIterator(const GroupIterator &orig);
	GroupIterator &operator++(void);
	GroupIterator &operator--(void);
	const int &operator*(void) const;
	const _iterator &getIter(void) const;
	const size_t &getSpan(void) const;
	void swap(const GroupIterator &other) const;
	void copyFrom(const GroupIterator &other) const;
	void insertToStream(std::ostream &os) const;
};

bool operator==(const GroupIterator &lhs, const GroupIterator &rhs);
bool operator!=(const GroupIterator &lhs, const GroupIterator &rhs);
GroupIterator &operator+=(GroupIterator &it, size_t amount);
GroupIterator &operator-=(GroupIterator &it, size_t amount);
GroupIterator operator+(const GroupIterator &it, size_t amount);
GroupIterator operator-(const GroupIterator &it, size_t amount);
size_t distance(const GroupIterator &lhs, const GroupIterator &rhs);
std::ostream &operator<<(std::ostream &os, const GroupIterator &it);
bool compareGroupIterator(const GroupIterator &lhs, const GroupIterator &rhs);

#endif
