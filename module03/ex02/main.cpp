#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("frag");
	a.attack("other");
	a.takeDamage(3);
	a.beRepaired(3);
	a.highFivesGuys();
	return (0);
}
