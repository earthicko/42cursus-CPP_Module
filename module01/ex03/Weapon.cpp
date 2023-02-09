#include "Weapon.hpp"

Weapon::Weapon(const std::string &newType):
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

void	Weapon::setType(const std::string &newType)
{
	type = newType;
}
