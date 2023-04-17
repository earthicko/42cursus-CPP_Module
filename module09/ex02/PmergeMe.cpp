#include "PmergeMe.hpp"

std::ostream	&operator<<(std::ostream &os, PmergeMe<std::vector<int> > lp)
{
	for (std::vector<int>::size_type i = 0; i < lp.getData().size(); i++)
		os << lp.getData()[i] << " ";
	return (os);
}

std::ostream	&operator<<(std::ostream &os, PmergeMe<std::list<int> > lp)
{
	for (std::list<int>::iterator it = lp.getData().begin(); it != lp.getData().end(); it++)
		os << *it << " ";
	return (os);
}
