#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

const std::string	Cat::_defaultType = "Cat";

Cat::Cat(void):
	Animal()
{
	std::cout << "Cat: Default constructor\n";
	type = Cat::_defaultType;
	brain = new Brain();
}

Cat::Cat(const Cat &orig):
	Animal(orig)
{
	std::cout << "Cat: Copy constructor\n";
	type = Cat::_defaultType;
	brain = new Brain(*orig.brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor\n";
	delete brain;
}

Cat	&Cat::operator=(const Cat &orig)
{
	Animal::operator=(orig);
	std::cout << "Cat: operator= w/ another Cat\n";
	type = Cat::_defaultType;
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
