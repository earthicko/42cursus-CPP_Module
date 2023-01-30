#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):
	_weapon(weapon),
	_name(name)
{
}

HumanA::HumanA(const HumanA &orig):
	_weapon(orig._weapon),
	_name(orig._name)
{
}

HumanA::~HumanA(void)
{
}

HumanA	&HumanA::operator=(const HumanA &orig)
{
	_weapon = orig._weapon;
	_name = orig._name;
	return (*this);
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
