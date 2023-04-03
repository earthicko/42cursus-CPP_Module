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
