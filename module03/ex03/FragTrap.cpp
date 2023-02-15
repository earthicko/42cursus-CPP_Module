#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	_hitPoint = _defaultHitPoint;
	_energyPoint = _defaultEnergyPoint;
	_attackDamage = _defaultAttackDamage;
	printStatus();
}

FragTrap::FragTrap(const FragTrap &orig):
	ClapTrap(orig)
{
	std::cout << "FragTrap copy constructor" << std::endl;
	_hitPoint = orig._hitPoint;
	_energyPoint = orig._energyPoint;
	_attackDamage = orig._attackDamage;
	printStatus();
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &orig)
{
	ClapTrap::operator=(orig);
	std::cout << "FragTrap copy assignment operator" << std::endl;
	_hitPoint = orig._hitPoint;
	_energyPoint = orig._energyPoint;
	_attackDamage = orig._attackDamage;
	printStatus();
	return (*this);
}

FragTrap::FragTrap(const std::string &name):
	ClapTrap(name)
{
	std::cout << "FragTrap constructor with name" << std::endl;
	_hitPoint = _defaultHitPoint;
	_energyPoint = _defaultEnergyPoint;
	_attackDamage = _defaultAttackDamage;
	printStatus();
}

void	FragTrap::highFivesGuys(void)
{
	printIdentifier();
	std::cout << "requests positive high fives." << std::endl;
}

void	FragTrap::printIdentifier(void)
{
	std::cout << "FragTrap " << _name << ": ";
}
