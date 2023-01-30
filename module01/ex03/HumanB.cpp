#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	_weapon(NULL),
	_name(name)
{
}

HumanB::HumanB(const HumanB &orig):
	_weapon(orig._weapon),
	_name(orig._name)
{
}

HumanB::~HumanB(void)
{
}

HumanB	&HumanB::operator=(const HumanB &orig)
{
	_weapon = orig._weapon;
	_name = orig._name;
	return (*this);
}

void	HumanB::attack(void) const
{
	if (_weapon)
	{
		std::cout << _name << " attacks with their ";
		std::cout << _weapon->getType() << std::endl;
	}
	else
		std::cout << _name << " can't attack without their weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
