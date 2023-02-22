#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ClapTrap("_clap_trap"),
	ScavTrap("_scav_trap"),
	FragTrap("_frag_trap"),
	_name("")
{
	std::cout << "DiamondTrap default constructor" << std::endl;
	_hitPoint = FragTrap::_defaultHitPoint;
	_energyPoint = ScavTrap::_defaultEnergyPoint;
	_attackDamage = FragTrap::_defaultAttackDamage;
	printStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig):
	ClapTrap(orig),
	ScavTrap(orig),
	FragTrap(orig),
	_name(orig._name)
{
	std::cout << "DiamondTrap copy constructor" << std::endl;
	_hitPoint = orig._hitPoint;
	_energyPoint = orig._energyPoint;
	_attackDamage = orig._attackDamage;
	printStatus();
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &orig)
{
	ClapTrap::operator=(orig);
	ScavTrap::operator=(orig);
	FragTrap::operator=(orig);
	std::cout << "DiamondTrap copy assignment operator" << std::endl;
	_name = orig._name;
	_hitPoint = orig._hitPoint;
	_energyPoint = orig._energyPoint;
	_attackDamage = orig._attackDamage;
	printStatus();
	return (*this);
}

DiamondTrap::DiamondTrap(const std::string &name):
	ClapTrap(name + "_clap_trap"),
	ScavTrap(name + "_scav_trap"),
	FragTrap(name + "_frag_trap"),
	_name(name)
{
	std::cout << "DiamondTrap constructor with name" << std::endl;
	_hitPoint = FragTrap::_defaultHitPoint;
	_energyPoint = ScavTrap::_defaultEnergyPoint;
	_attackDamage = FragTrap::_defaultAttackDamage;
	printStatus();
}

void	DiamondTrap::whoAmI(void)
{
	printIdentifier();
	std::cout << "DiamondTrap name: " << _name << ", ";
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::printIdentifier(void)
{
	std::cout << "DiamondTrap " << _name << ": ";
}
