#include <iostream>
#include <string>
#include "Cure.hpp"

const std::string	Cure::_typename = "cure";

Cure::Cure(void):
	AMateria(Cure::_typename)
{
	std::cout << "Cure: Default constructor\n";
}

Cure::Cure(const Cure &orig):
	AMateria(Cure::_typename)
{
	std::cout << "Cure: Copy constructor\n";
}

Cure::~Cure(void)
{
	std::cout << "Cure: Destructor\n";
}

Cure	&Cure::operator=(const Cure &orig)
{
	std::cout << "Cure: operator=\n";
	_type = Cure::_typename;
}

AMateria	*Cure::clone(void) const
{
	AMateria	*cloned;

	std::cout << "Cure: clone\n";
	cloned = new Cure(*this);
	return (cloned);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "Cure: use\n";
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
