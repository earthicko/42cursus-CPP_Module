#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):
	ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
	printStatus();
}

ScavTrap::ScavTrap(const ScavTrap &orig):
	ClapTrap(orig)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
	printStatus();
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &orig)
{
	ClapTrap::operator=(orig);
	std::cout << "ScavTrap copy assignment operator" << std::endl;
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
	printStatus();
	return (*this);
}

ScavTrap::ScavTrap(const std::string &name):
	ClapTrap(name)
{
	std::cout << "ScavTrap constructor with name" << std::endl;
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
	printStatus();
}

void	ScavTrap::guardGate(void)
{
	printIdentifier();
	std::cout << "now in guard mode." << std::endl;
}

void	ScavTrap::printIdentifier(void)
{
	std::cout << "ScavTrap " << getName() << ": ";
}
