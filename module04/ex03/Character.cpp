#include <iostream>
#include "Character.hpp"

Character::Character(void):
	_name("")
{
	std::cout << "Character: Default constructor\n";
	for (int i = 0; i < Character::_nSlots; i++)
		_slot[i] = NULL;
}

Character::Character(const Character &orig):
	_name(orig._name)
{
	std::cout << "Character: Copy constructor\n";
	for (int i = 0; i < Character::_nSlots; i++)
		_slot[i] = orig._slot[i];
}

Character::~Character(void)
{
	std::cout << "Character: Destructor\n";
}

Character	&Character::operator=(const Character &orig)
{
	std::cout << "Character: operator=\n";
	if (&orig == this)
		return (*this);
	_name = orig._name;
	for (int i = 0; i < Character::_nSlots; i++)
		_slot[i] = orig._slot[i];
	return (*this);
}

Character::Character(const std::string &name):
	_name(name)
{
	std::cout << "Character: Default constructor with name\n";
	for (int i = 0; i < Character::_nSlots; i++)
		_slot[i] = NULL;
}

std::string const	&Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	std::cout << "Character: equip\n";
	for (int i = 0; i < Character::_nSlots; i++)
	{
		if (!_slot[i])
		{
			_slot[i] = m;
			return ;
		}
	}
	std::cerr << "Character: no slots are available\n";
}

void	Character::unequip(int idx)
{
	std::cout << "Character: unequip\n";
	if (idx < 0 || idx >= Character::_nSlots)
	{
		std::cerr << "Character: idx " << idx << " is out of bound ";
		std::cerr << "[0:" << Character::_nSlots << ")\n";
		return ;
	}
	if (_slot[idx])
		_slot[idx] = NULL;
	else
		std::cerr << "Character: slot " << idx << " is empty\n";
}

void	Character::use(int idx, ICharacter& target)
{
	std::cout << "Character: use\n";
	if (idx < 0 || idx >= Character::_nSlots)
	{
		std::cerr << "Character: idx " << idx << " is out of bound ";
		std::cerr << "[0:" << Character::_nSlots << ")\n";
		return ;
	}
	if (_slot[idx])
		_slot[idx]->use(target);
	else
		std::cerr << "Character: slot " << idx << " is empty\n";
}
