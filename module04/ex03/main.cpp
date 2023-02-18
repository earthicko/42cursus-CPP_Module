#include <cstdlib>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	{
		IMateriaSource	*src;
		AMateria		*tmp;

		src = new MateriaSource();
		tmp = new Ice();
		for(int i = 0; i < 10; i++)
			src->learnMateria(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		delete tmp;
		tmp = src->createMateria("nonexistent");
		delete tmp;
		tmp = src->createMateria("");
		delete tmp;
		delete src;
	}
	{
		ICharacter	*boba;
		ICharacter	*kiki;
		AMateria	*cure;
		AMateria	*ice;

		boba = new Character("boba");
		kiki = new Character("kiki");
		cure = new Cure();
		ice = new Ice();
		boba->equip(cure);
		for (int i = 0; i < 10; i++)
			boba->unequip(i);
		boba->equip(ice);
		boba->equip(cure);
		boba->unequip(0);
		for (int i = 0; i < 10; i++)
			boba->equip(ice);
		for (int i = 0; i < 10; i++)
			boba->use(i, *kiki);
		boba->unequip(1);
		boba->unequip(3);
		for (int i = 0; i < 10; i++)
			boba->use(i, *kiki);
		delete boba;
		delete kiki;
		delete cure;
		delete ice;
	}
	{
		IMateriaSource	*src;
		AMateria		*ice;
		AMateria		*cure;
		AMateria		*tmp;
		ICharacter		*me;
		ICharacter		*bob;

		src = new MateriaSource();
		ice = new Ice();
		cure = new Cure();
		src->learnMateria(ice);
		src->learnMateria(cure);
		me = new Character("me");
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	system("leaks exec");
	return (0);
}
