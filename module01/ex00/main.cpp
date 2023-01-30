#include <string>
#include <stdlib.h>
#include "Zombie.hpp"
#include "ZombieUtils.hpp"

int	main(void)
{
	Zombie	*zombie;

	randomChump("PolarBear");
	randomChump("Holly");
	zombie = newZombie("donghyle");
	zombie->announce();
	delete zombie;
	zombie = newZombie("seonjeon");
	zombie->announce();
	delete zombie;
	system("leaks ex00");
	return (0);
}
