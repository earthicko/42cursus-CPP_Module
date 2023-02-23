#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

const std::string	Dog::_defaultType = "Dog";

Dog::Dog(void):
	Animal()
{
	std::cout << "Dog: Default constructor\n";
	type = Dog::_defaultType;
	brain = new Brain();
}

Dog::Dog(const Dog &orig):
	Animal(orig)
{
	std::cout << "Dog: Copy constructor\n";
	type = Dog::_defaultType;
	brain = new Brain(*orig.brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog: Destructor\n";
	delete brain;
}

Dog	&Dog::operator=(const Dog &orig)
{
	Animal::operator=(orig);
	std::cout << "Dog: operator= w/ another Dog\n";
	type = Dog::_defaultType;
	brain = new Brain(*orig.brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: makeSound\n";
	std::cout << "Dog: makes Dog sound\n";
}

void	Dog::setIdea(const std::string &idea, int i)
{
	brain->setIdea(idea, i);
}

const std::string	&Dog::getIdea(int i) const
{
	return (brain->getIdea(i));
}
