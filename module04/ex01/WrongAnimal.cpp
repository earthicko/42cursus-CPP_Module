#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):
	type("")
{
	std::cout << "WrongAnimal: Default constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &orig):
	type(orig.type)
{
	std::cout << "WrongAnimal: Copy constructor\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal: Destructor\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &orig)
{
	std::cout << "WrongAnimal: operator= w/ another WrongAnimal\n";
	type = orig.type;
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
