#ifndef GROUPITERATOR_HPP
#define GROUPITERATOR_HPP

#include <iostream>
#include <list>

class GroupIterator
{
  private:
	typedef std::list<int>::iterator _iterator;
	std::list<int> &_l;
	ssize_t _idx;
	ssize_t _len;
	_iterator _begin;
	_iterator _comp;
	ssize_t _span;

  public:
	GroupIterator(std::list<int> &l, ssize_t len, _iterator it, ssize_t span);
	GroupIterator(const GroupIterator &orig);

	bool valid(void) const;

	GroupIterator &operator++(void);
	GroupIterator &operator--(void);
	const int &operator*(void) const;

	const _iterator &getIter(void) const;
	const ssize_t &getIdx(void) const;
	const ssize_t &getSpan(void) const;

	void swap(const GroupIterator &other) const;
	void copyFrom(const GroupIterator &other) const;
	void insertToStream(std::ostream &os) const;
};

bool operator==(const GroupIterator &lhs, const GroupIterator &rhs);
bool operator!=(const GroupIterator &lhs, const GroupIterator &rhs);
GroupIterator &operator+=(GroupIterator &it, ssize_t amount);
GroupIterator &operator-=(GroupIterator &it, ssize_t amount);
GroupIterator operator+(const GroupIterator &it, ssize_t amount);
GroupIterator operator-(const GroupIterator &it, ssize_t amount);
ssize_t distance(const GroupIterator &lhs, const GroupIterator &rhs);
std::ostream &operator<<(std::ostream &os, const GroupIterator &it);
bool compareGroupIterator(const GroupIterator &lhs, const GroupIterator &rhs);

#endif
