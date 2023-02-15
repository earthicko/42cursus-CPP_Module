#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):
	ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	_hitPoint = _defaultHitPoint;
	_energyPoint = _defaultEnergyPoint;
	_attackDamage = _defaultAttackDamage;
	printStatus();
}

ScavTrap::ScavTrap(const ScavTrap &orig):
	ClapTrap(orig)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
	_hitPoint = orig._hitPoint;
	_energyPoint = orig._hitPoint;
	_attackDamage = orig._hitPoint;
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
	_hitPoint = orig._hitPoint;
	_energyPoint = orig._hitPoint;
	_attackDamage = orig._hitPoint;
	printStatus();
	return (*this);
}

ScavTrap::ScavTrap(const std::string &name):
	ClapTrap(name)
{
	std::cout << "ScavTrap constructor with name" << std::endl;
	_hitPoint = _defaultHitPoint;
	_energyPoint = _defaultEnergyPoint;
	_attackDamage = _defaultAttackDamage;
	printStatus();
}

void	ScavTrap::guardGate(void)
{
	printIdentifier();
	std::cout << "now in guard mode." << std::endl;
}

void	ScavTrap::printIdentifier(void)
{
	std::cout << "ScavTrap " << _name << ": ";
}
