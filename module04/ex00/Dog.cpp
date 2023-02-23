#include <iostream>
#include "Dog.hpp"

const std::string	Dog::_defaultType = "Dog";

Dog::Dog(void):
	Animal()
{
	std::cout << "Dog: Default constructor\n";
	type = Dog::_defaultType;
}

Dog::Dog(const Dog &orig):
	Animal(orig)
{
	(void)orig;
	std::cout << "Dog: Copy constructor\n";
	type = Dog::_defaultType;
}

Dog::~Dog(void)
{
	std::cout << "Dog: Destructor\n";
}

Dog	&Dog::operator=(const Dog &orig)
{
	(void)orig;
	Animal::operator=(orig);
	std::cout << "Dog: operator= w/ another Dog\n";
	type = Dog::_defaultType;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: makeSound\n";
	std::cout << "Dog: makes dog sound\n";
}
