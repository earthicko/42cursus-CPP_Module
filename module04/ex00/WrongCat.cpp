#include <iostream>
#include "WrongCat.hpp"

const std::string	WrongCat::_defaultType = "WrongCat";

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat: Default constructor\n";
	type = WrongCat::_defaultType;
}

WrongCat::WrongCat(const WrongCat &orig):
	WrongAnimal(orig)
{
	(void)orig;
	std::cout << "WrongCat: Copy constructor\n";
	type = WrongCat::_defaultType;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &orig)
{
	std::cout << "WrongCat: operator= w/ another WrongCat\n";
	if (&orig == this)
		return (*this);
	type = WrongCat::_defaultType;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: makeSound\n";
	std::cout << "WrongCat: makes wrong cat sound\n";
}
