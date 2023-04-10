#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	MutantStack<int>							mstack;
	MutantStack<int>::iterator					iter;
	MutantStack<int>::const_iterator			citer;
	MutantStack<int>::reverse_iterator			riter;
	MutantStack<int>::const_reverse_iterator	criter;

	for (int i = 0; i < 4; i++)
	{
		mstack.push(1 << i);
		std::cout << "Pushed " << mstack.top() << "\n";
	}
	for (iter = mstack.begin(); iter != mstack.end(); iter++)
		std::cout << "Iter              : " << *iter << "\n";
	for (citer = mstack.cbegin(); citer != mstack.cend(); citer++)
		std::cout << "Const Iter        : " << *citer << "\n";
	for (riter = mstack.rbegin(); riter != mstack.rend(); riter++)
		std::cout << "Reverse Iter      : " << *riter << "\n";
	for (criter = mstack.crbegin(); criter != mstack.crend(); criter++)
		std::cout << "Const Reverse Iter: " << *criter << "\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Will pop " << mstack.top() << "\n";
		mstack.pop();
	}
	return (0);
}
