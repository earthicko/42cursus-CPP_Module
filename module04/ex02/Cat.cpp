#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
	std::cout << "Cat: Default constructor\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &orig)
{
	std::cout << "Cat: Copy constructor\n";
	type = orig.type;
	brain = new Brain(*orig.brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor\n";
	delete brain;
}

Cat	&Cat::operator=(const Cat &orig)
{
	std::cout << "Cat: operator= w/ another Cat\n";
	type = orig.type;
	brain = new Brain(*orig.brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: makeSound\n";
	std::cout << "Cat: makes cat sound\n";
}

void	Cat::setIdea(const std::string &idea, int i)
{
	brain->setIdea(idea, i);
}

const std::string	&Cat::getIdea(int i) const
{
	return (brain->getIdea(i));
}
