#include "Weapon.hpp"

Weapon::Weapon(void):
	type("")
{
}

Weapon::Weapon(const Weapon &weapon):
	type(weapon.type)
{
}

Weapon::~Weapon(void)
{
	return ;
}

Weapon	&Weapon::operator=(const Weapon &weapon)
{
	type = weapon.type;
	return (*this);
}

Weapon::Weapon(std::string newType):
	type(newType)
{
}

const std::string	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}
