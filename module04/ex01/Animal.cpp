#include <iostream>
#include "Animal.hpp"

const std::string	Animal::_defaultType = "";

Animal::Animal(void):
	type(Animal::_defaultType)
{
	std::cout << "Animal: Default constructor\n";
}

Animal::Animal(const Animal &orig):
	type(Animal::_defaultType)
{
	(void)orig;
	std::cout << "Animal: Copy constructor\n";
}

Animal::~Animal(void)
{
	std::cout << "Animal: Destructor\n";
}

Animal	&Animal::operator=(const Animal &orig)
{
	(void)orig;
	std::cout << "Animal: operator= w/ another Animal\n";
	type = Animal::_defaultType;
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
