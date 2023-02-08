#include "Weapon.hpp"

Weapon::Weapon(std::string newType):
	type(newType)
{
}

Weapon::~Weapon(void)
{
}

const std::string	&Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}
