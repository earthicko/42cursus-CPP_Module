#include <iostream>
#include <string>
#include "AMateria.hpp"

AMateria::AMateria(const std::string &type):
	_type(type)
{
	std::cout << "AMateria: Default constructor\n";
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria: Destructor\n";
}

const std::string	&AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "AMateria: use\n";
	(void)target;
}
