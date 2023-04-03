#include "MutantStack.hpp"

template <class _Tp>
MutantStack<_Tp>::MutantStack(void):
	std::stack<_Tp>()
{
}

template <class _Tp>
MutantStack<_Tp>::MutantStack(const MutantStack<_Tp> &orig):
	std::stack<_Tp>(orig)
{
	(void)orig;
}

template <class _Tp>
MutantStack<_Tp>::~MutantStack(void)
{
}

template <class _Tp>
MutantStack<_Tp>	&MutantStack<_Tp>::operator=(const MutantStack<_Tp> &orig)
{
	std::stack<_Tp>::operator=(orig);
}

template <class _Tp>
typename MutantStack<_Tp>::iterator	MutantStack<_Tp>::begin(void)
{
	return (std::stack<_Tp>::c.begin());
}

template <class _Tp>
typename MutantStack<_Tp>::iterator	MutantStack<_Tp>::end(void)
{
	return (std::stack<_Tp>::c.end());
}
