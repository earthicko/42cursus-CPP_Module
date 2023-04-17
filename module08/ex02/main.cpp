#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	testMutantStack(void)
{
	MutantStack<int>							mstack;
	MutantStack<int>::iterator					iter;
	MutantStack<int>::const_iterator			citer;
	MutantStack<int>::reverse_iterator			riter;
	MutantStack<int>::const_reverse_iterator	criter;

	std::cout << __func__ << "() ===========================================\n";
	for (int i = 0; i < 4; i++)
	{
		mstack.push(1 << i);
		std::cout << "Pushed " << mstack.top() << "\n";
	}
	for (iter = mstack.begin(); iter != mstack.end(); iter++)
		std::cout << "Iter              : " << *iter << "\n";
	for (riter = mstack.rbegin(); riter != mstack.rend(); riter++)
		std::cout << "Reverse Iter      : " << *riter << "\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Will pop " << mstack.top() << "\n";
		mstack.pop();
	}
}

void	testList(void)
{
	std::list<int>							mstack;
	std::list<int>::iterator				iter;
	std::list<int>::const_iterator			citer;
	std::list<int>::reverse_iterator		riter;
	std::list<int>::const_reverse_iterator	criter;

	std::cout << __func__ << "() ===========================================\n";
	for (int i = 0; i < 4; i++)
	{
		mstack.push_back(1 << i);
		std::cout << "Pushed " << mstack.back() << "\n";
	}
	for (iter = mstack.begin(); iter != mstack.end(); iter++)
		std::cout << "Iter              : " << *iter << "\n";
	for (riter = mstack.rbegin(); riter != mstack.rend(); riter++)
		std::cout << "Reverse Iter      : " << *riter << "\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Will pop " << mstack.front() << "\n";
		mstack.pop_front();
	}
}

int	main(void)
{
	testMutantStack();
	testList();
	return (0);
}
