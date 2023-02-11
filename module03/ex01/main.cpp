#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("scav");
	a.attack("other");
	a.takeDamage(3);
	a.beRepaired(3);
	return (0);
}
