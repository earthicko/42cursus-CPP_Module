#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template <class _Tp>
class	MutantStack: public std::stack<_Tp>
{
public:
	typedef typename std::deque<_Tp>::iterator	iterator;

				MutantStack(void);
				MutantStack(const MutantStack &orig);
				~MutantStack(void);
	MutantStack	&operator=(const MutantStack &orig);

	iterator	begin(void);
	iterator	end(void);
};

# include "MutantStack.tpp"

#endif
