#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
	printStatus();
}

FragTrap::FragTrap(const FragTrap &orig):
	ClapTrap(orig)
{
	std::cout << "FragTrap copy constructor" << std::endl;
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
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
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
	printStatus();
	return (*this);
}

FragTrap::FragTrap(const std::string &name):
	ClapTrap(name)
{
	std::cout << "FragTrap constructor with name" << std::endl;
	setHitPoint(_defaultHitPoint);
	setEnergyPoint(_defaultEnergyPoint);
	setAttackDamage(_defaultAttackDamage);
	printStatus();
}

void	FragTrap::highFivesGuys(void)
{
	printIdentifier();
	std::cout << "requests positive high five." << std::endl;
}

void	FragTrap::printIdentifier(void)
{
	std::cout << "FragTrap " << getName() << ": ";
}
