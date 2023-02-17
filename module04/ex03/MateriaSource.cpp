#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource: Default constructor\n";
	for (int i = 0; i < MateriaSource::_nSlots; i++)
		_slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &orig)
{
	std::cout << "MateriaSource: Copy constructor\n";
	for (int i = 0; i < MateriaSource::_nSlots; i++)
	{
		if (_slot[i])
			_slot[i] = orig._slot[i]->clone();
		else
			_slot[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource: Destructor\n";
	for (int i = 0; i < MateriaSource::_nSlots; i++)
	{
		if (_slot[i])
			delete _slot[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &orig)
{
	std::cout << "MateriaSource: operator=\n";
	for (int i = 0; i < MateriaSource::_nSlots; i++)
	{
		if (_slot[i])
			_slot[i] = orig._slot[i]->clone();
		else
			_slot[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "MateriaSource: learnMateria\n";
	for (int i = 0; i < MateriaSource::_nSlots; i++)
	{
		if (!_slot[i])
		{
			_slot[i] = m->clone();
			return ;
		}
	}
	std::cerr << "MateriaSource: no slots are available\n";
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	std::cout << "MateriaSource: createMateria\n";
	for (int i = 0; i < MateriaSource::_nSlots; i++)
	{
		if (_slot[i] && _slot[i]->getType() == type)
			return (_slot[i]->clone());
	}
	std::cerr << "MateriaSource: no matching materia of type " << type << "\n";
	return (NULL);
}
