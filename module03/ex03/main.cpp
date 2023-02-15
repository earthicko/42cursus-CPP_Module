#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("diamond");
	a.attack("other");
	a.takeDamage(3);
	a.beRepaired(3);
	a.whoAmI();
	return (0);
}
