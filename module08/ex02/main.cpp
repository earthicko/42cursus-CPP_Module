#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	MutantStack<int>	mstack;

	for (int i = 0; i < 4; i++)
	{
		mstack.push(1 << i);
		std::cout << "Pushed " << mstack.top() << "\n";
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Will pop " << mstack.top() << "\n";
		mstack.pop();
	}
	return (0);
}
