#include <iostream>
#include "WrongAnimal.hpp"

const std::string	WrongAnimal::_defaultType = "";

WrongAnimal::WrongAnimal(void):
	type(WrongAnimal::_defaultType)
{
	std::cout << "WrongAnimal: Default constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &orig):
	type(WrongAnimal::_defaultType)
{
	(void)orig;
	std::cout << "WrongAnimal: Copy constructor\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal: Destructor\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &orig)
{
	(void)orig;
	std::cout << "WrongAnimal: operator= w/ another WrongAnimal\n";
	if (&orig == this)
		return (*this);
	type = WrongAnimal::_defaultType;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal: makeSound\n";
}

const std::string	&WrongAnimal::getType(void) const
{
	return (type);
}
