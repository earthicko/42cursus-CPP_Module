#ifndef GROUPPOINTER_HPP
#define GROUPPOINTER_HPP

#include <iostream>
#include <list>
#include <vector>

class GroupPointer
{
  private:
	std::vector<int> &_v;
	ssize_t _idx;
	ssize_t _len;
	int *_begin;
	int *_comp;
	ssize_t _span;

  public:
	GroupPointer(std::vector<int> &v, ssize_t len, ssize_t idx, ssize_t span);
	GroupPointer(const GroupPointer &orig);

	bool valid(void) const;

	GroupPointer &operator++(void);
	GroupPointer &operator--(void);
	const int &operator*(void) const;
	void advance(ssize_t amount);

	int *getPtr(void) const;
	const ssize_t &getIdx(void) const;
	const ssize_t &getSpan(void) const;

	void swap(const GroupPointer &other) const;
	void copyFrom(const GroupPointer &other) const;
	void insertToStream(std::ostream &os) const;
};

bool operator==(const GroupPointer &lhs, const GroupPointer &rhs);
bool operator!=(const GroupPointer &lhs, const GroupPointer &rhs);
GroupPointer &operator+=(GroupPointer &it, ssize_t amount);
GroupPointer &operator-=(GroupPointer &it, ssize_t amount);
GroupPointer operator+(const GroupPointer &it, ssize_t amount);
GroupPointer operator-(const GroupPointer &it, ssize_t amount);
ssize_t distance(const GroupPointer &lhs, const GroupPointer &rhs);
std::ostream &operator<<(std::ostream &os, const GroupPointer &it);
bool compareGroupPointer(const GroupPointer &lhs, const GroupPointer &rhs);

#endif
