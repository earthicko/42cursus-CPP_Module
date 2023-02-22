#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("scav");
	ScavTrap b("trap");
	a.attack("other");
	a.takeDamage(3);
	a.beRepaired(1);
	a.guardGate();
	b = a;
	b.beRepaired(3);
	return (0);
}
