#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name(""),
	_hitPoint(ClapTrap::_defaultHitPoint),
	_energyPoint(ClapTrap::_defaultEnergyPoint),
	_attackDamage(ClapTrap::_defaultAttackDamage)
{
	std::cout << "ClapTrap default constructor" << std::endl;
	printStatus();
}

ClapTrap::ClapTrap(const ClapTrap &orig):
	_name(orig._name),
	_hitPoint(orig._hitPoint),
	_energyPoint(orig._energyPoint),
	_attackDamage(orig._attackDamage)
{
	std::cout << "ClapTrap copy constructor" << std::endl;
	printStatus();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &orig)
{
	_name = orig._name;
	_hitPoint = orig._hitPoint;
	_energyPoint = orig._energyPoint;
	_attackDamage = orig._attackDamage;
	std::cout << "ClapTrap copy assignment operator" << std::endl;
	printStatus();
	return (*this);
}

ClapTrap::ClapTrap(const std::string &name):
	_name(name),
	_hitPoint(ClapTrap::_defaultHitPoint),
	_energyPoint(ClapTrap::_defaultEnergyPoint),
	_attackDamage(ClapTrap::_defaultAttackDamage)
{
	std::cout << "ClapTrap constructor with name" << std::endl;
	printStatus();
}

void	ClapTrap::attack(const std::string &target)
{
	printIdentifier();
	if (_energyPoint == 0)
		std::cout << "cannot attack with energy point being empty." << std::endl;
	else if (_hitPoint == 0)
		std::cout << "cannot attack with hit point being empty." << std::endl;
	else
	{
		std::cout << "attacks " << target << " with ";
		std::cout << "damage point " << _attackDamage << "." << std::endl;
		_energyPoint--;
	}
}

void	ClapTrap::takeDamage(t_uint amount)
{
	printIdentifier();
	std::cout << "takes damage of " << amount << ". ";
	if (amount > _hitPoint)
		_hitPoint = 0;
	else
		_hitPoint -= amount;
	std::cout << "Hit point decreased to " << _hitPoint << "." << std::endl;
}

void	ClapTrap::beRepaired(t_uint amount)
{
	printIdentifier();
	if (_energyPoint == 0)
		std::cout << "cannot be repaired with energy point being empty." << std::endl;
	else if (_hitPoint == 0)
		std::cout << "cannot be repaired with hit point being empty." << std::endl;
	else
	{
		_hitPoint += amount;
		std::cout << "repairs itself by " << amount << ". ";
		std::cout << "Hit point increased to " << _hitPoint << "." << std::endl;
		_energyPoint--;
	}
}

const std::string	&ClapTrap::getName(void) const
{
	return (_name);
}

void	ClapTrap::setHitPoint(t_uint hitPoint)
{
	_hitPoint = hitPoint;
}

void	ClapTrap::setEnergyPoint(t_uint energyPoint)
{
	_energyPoint = energyPoint;
}

void	ClapTrap::setAttackDamage(t_uint attackDamage)
{
	_attackDamage = attackDamage;
}

void	ClapTrap::printIdentifier(void)
{
	std::cout << "ClapTrap " << _name << ": ";
}

void	ClapTrap::printStatus(void)
{
	printIdentifier();
	std::cout << "Hit point " << _hitPoint << ", ";
	std::cout << "Energy point " << _energyPoint << ", ";
	std::cout << "Attack damage " << _attackDamage << std::endl;
}
