#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain: Default constructor\n";
}

Brain::Brain(const Brain &orig)
{
	std::cout << "Brain: Copy constructor\n";
	for (int i = 0; i < Brain::nIdeas; i++)
		ideas[i] = orig.ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain: Destructor\n";
}

Brain	&Brain::operator=(const Brain &orig)
{
	std::cout << "Brain: operator= w/ another Brain\n";
	if (&orig == this)
		return (*this);
	for (int i = 0; i < Brain::nIdeas; i++)
		ideas[i] = orig.ideas[i];
	return (*this);
}

void	Brain::setIdea(const std::string &idea, int i)
{
	if (i < 0 || i >= Brain::nIdeas)
	{
		printIndexError(i);
		return ;
	}
	std::cout << "Set idea[" << i << "] to " << idea << "\n";
	ideas[i] = idea;
}

const std::string	&Brain::getIdea(int i) const
{
	if (i < 0 || i >= Brain::nIdeas)
	{
		printIndexError(i);
		i = i % Brain::nIdeas;
		std::cerr << "Wrapping index to " << i << "\n";
	}
	std::cout << "Get " << ideas[i] << "from idea[" << i << "]\n";
	return (ideas[i]);
}

void	Brain::printIndexError(int i) const
{
	std::cerr << "Brain: Index " << i << " out of bound [0, " << Brain::nIdeas << ")\n";
}
