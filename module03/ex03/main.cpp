#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("diamond");
	DiamondTrap b(a);
	a.attack("other");
	a.takeDamage(3);
	a.beRepaired(3);
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
	b = a;
	return (0);
}
