#include <iostream>
#include <string>
#include "AMateria.hpp"

AMateria::AMateria(const std::string &type):
	_type(type)
{
	std::cout << "AMateria: Default constructor\n";
}

const std::string	&AMateria::getType(void) const
{
	std::cout << "AMateria: getType\n";
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "AMateria: use\n";
	(void)target;
}
