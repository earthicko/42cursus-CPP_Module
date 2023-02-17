#include <iostream>
#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat: Default constructor\n";
	type = "Cat";
}

Cat::Cat(const Cat &orig)
{
	std::cout << "Cat: Copy constructor\n";
	type = orig.type;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor\n";
}

Cat	&Cat::operator=(const Cat &orig)
{
	std::cout << "Cat: operator= w/ another Cat\n";
	type = orig.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: makeSound\n";
	std::cout << "Cat: makes cat sound\n";
}
