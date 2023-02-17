#include <iostream>
#include "Animal.hpp"

Animal::Animal(void):
	type("")
{
	std::cout << "Animal: Default constructor\n";
}

Animal::Animal(const Animal &orig):
	type(orig.type)
{
	std::cout << "Animal: Copy constructor\n";
}

Animal::~Animal(void)
{
	std::cout << "Animal: Destructor\n";
}

Animal	&Animal::operator=(const Animal &orig)
{
	std::cout << "Animal: operator= w/ another Animal\n";
	type = orig.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal: makeSound\n";
}

const std::string	&Animal::getType(void) const
{
	return (type);
}
