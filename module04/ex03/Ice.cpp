#include <iostream>
#include <string>
#include "Ice.hpp"

const std::string	Ice::_typename = "ice";

Ice::Ice(void):
	AMateria(Ice::_typename)
{
	std::cout << "Ice: Default constructor\n";
}

Ice::Ice(const Ice &orig):
	AMateria(Ice::_typename)
{
	std::cout << "Ice: Copy constructor\n";
}

Ice::~Ice(void)
{
	std::cout << "Ice: Destructor\n";
}

Ice	&Ice::operator=(const Ice &orig)
{
	std::cout << "Ice: operator=\n";
	_type = Ice::_typename;
}

AMateria	*Ice::clone(void) const
{
	AMateria	*cloned;

	std::cout << "Ice: clone\n";
	cloned = new Ice(*this);
	return (cloned);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "Ice: use\n";
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
