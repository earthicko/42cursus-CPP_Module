#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("clap");
	ClapTrap b("trap");

	a.attack("trap");
	a.attack("trap");
	a.attack("trap");
	a.attack("trap");
	a.attack("trap");
	a.attack("trap");
	a.attack("trap");
	b.attack("clap");
	a.takeDamage(3);
	a.takeDamage(6);
	a.beRepaired(2);
	a.beRepaired(1);
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(1);
	b.takeDamage(10);
	return (0);
}
