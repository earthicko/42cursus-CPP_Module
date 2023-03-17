#include <iostream>
#include "Cat.hpp"

const std::string	Cat::_defaultType = "Cat";

Cat::Cat(void):
	Animal()
{
	std::cout << "Cat: Default constructor\n";
	type = Cat::_defaultType;
}

Cat::Cat(const Cat &orig):
	Animal(orig)
{
	(void)orig;
	std::cout << "Cat: Copy constructor\n";
	type = Cat::_defaultType;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor\n";
}

Cat	&Cat::operator=(const Cat &orig)
{
	Animal::operator=(orig);
	std::cout << "Cat: operator= w/ another Cat\n";
	if (&orig == this)
		return (*this);
	type = Cat::_defaultType;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: makeSound\n";
	std::cout << "Cat: makes cat sound\n";
}
