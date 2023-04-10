#include "MutantStack.hpp"

template <class _Tp, class _Container>
MutantStack<_Tp, _Container>::MutantStack(void):
	std::stack<_Tp, _Container>()
{
}

template <class _Tp, class _Container>
MutantStack<_Tp, _Container>::MutantStack(const MutantStack<_Tp, _Container> &orig):
	std::stack<_Tp, _Container>(orig)
{
	(void)orig;
}

template <class _Tp, class _Container>
MutantStack<_Tp, _Container>::~MutantStack(void)
{
}

template <class _Tp, class _Container>
MutantStack<_Tp, _Container>	&MutantStack<_Tp, _Container>::operator=(const MutantStack<_Tp, _Container> &orig)
{
	std::stack<_Tp, _Container>::operator=(orig);
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::iterator	MutantStack<_Tp, _Container>::begin(void)
{
	return (std::stack<_Tp, _Container>::c.begin());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_iterator	MutantStack<_Tp, _Container>::begin(void) const
{
	return (std::stack<_Tp, _Container>::c.begin());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::iterator	MutantStack<_Tp, _Container>::end(void)
{
	return (std::stack<_Tp, _Container>::c.end());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_iterator	MutantStack<_Tp, _Container>::end(void) const
{
	return (std::stack<_Tp, _Container>::c.end());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::reverse_iterator	MutantStack<_Tp, _Container>::rbegin(void)
{
	return (std::stack<_Tp, _Container>::c.rbegin());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_reverse_iterator	MutantStack<_Tp, _Container>::rbegin(void) const
{
	return (std::stack<_Tp, _Container>::c.rbegin());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::reverse_iterator	MutantStack<_Tp, _Container>::rend(void)
{
	return (std::stack<_Tp, _Container>::c.rend());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_reverse_iterator	MutantStack<_Tp, _Container>::rend(void) const
{
	return (std::stack<_Tp, _Container>::c.rend());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_iterator	MutantStack<_Tp, _Container>::cbegin(void) const
{
	return (std::stack<_Tp, _Container>::c.cbegin());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_iterator	MutantStack<_Tp, _Container>::cend(void) const
{
	return (std::stack<_Tp, _Container>::c.cend());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_reverse_iterator	MutantStack<_Tp, _Container>::crbegin(void) const
{
	return (std::stack<_Tp, _Container>::c.crbegin());
}

template <class _Tp, class _Container>
typename MutantStack<_Tp, _Container>::const_reverse_iterator	MutantStack<_Tp, _Container>::crend(void) const
{
	return (std::stack<_Tp, _Container>::c.crend());
}
