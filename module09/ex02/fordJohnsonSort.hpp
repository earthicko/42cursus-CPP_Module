#ifndef FORDJOHNSONSORT_HPP
#define FORDJOHNSONSORT_HPP

#include "GroupIterator.hpp"
#include "GroupPointer.hpp"

void fordJohnsonSortImpl(std::list<int> &l, ssize_t len, GroupIterator &begin, GroupIterator &end);
void fordJohnsonSortImpl(std::vector<int> &v, GroupPointer &begin, GroupPointer &end);

#endif
