#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template <class _Tp, class _Container = std::deque<_Tp> >
class	MutantStack: public std::stack<_Tp, _Container>
{
public:
				MutantStack(void);
				MutantStack(const MutantStack &orig);
				~MutantStack(void);
	MutantStack	&operator=(const MutantStack &orig);
};

# include "MutantStack.tpp"

#endif
