#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon):
	_weapon(weapon),
	_name(name)
{
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
