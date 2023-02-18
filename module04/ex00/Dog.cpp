#include <iostream>
#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog: Default constructor\n";
	type = "Dog";
}

Dog::Dog(const Dog &orig):
	Animal(orig)
{
	std::cout << "Dog: Copy constructor\n";
	type = orig.type;
}

Dog::~Dog(void)
{
	std::cout << "Dog: Destructor\n";
}

Dog	&Dog::operator=(const Dog &orig)
{
	std::cout << "Dog: operator= w/ another Dog\n";
	type = orig.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: makeSound\n";
	std::cout << "Dog: makes dog sound\n";
}
