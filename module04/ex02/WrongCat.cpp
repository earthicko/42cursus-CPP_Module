#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat: Default constructor\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &orig)
{
	std::cout << "WrongCat: Copy constructor\n";
	type = orig.type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &orig)
{
	std::cout << "WrongCat: operator= w/ another WrongCat\n";
	type = orig.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: makeSound\n";
	std::cout << "WrongCat: makes wrong cat sound\n";
}
