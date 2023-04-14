#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template <class _Tp, class _Container = std::deque<_Tp> >
class	MutantStack: public std::stack<_Tp, _Container>
{
public:
	typedef typename _Container::iterator				iterator;
	typedef typename _Container::const_iterator			const_iterator;
	typedef typename _Container::reverse_iterator		reverse_iterator;
	typedef typename _Container::const_reverse_iterator	const_reverse_iterator;

							MutantStack(void);
							MutantStack(const MutantStack &orig);
							~MutantStack(void);
	MutantStack				&operator=(const MutantStack &orig);

	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;

	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
