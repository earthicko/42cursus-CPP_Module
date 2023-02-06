#include <string>
#include "Zombie.hpp"
#include "ZombieUtils.hpp"

int	main(void)
{
	Zombie	*zombie;

	randomChump("dahkang");
	randomChump("hyeyukim");
	zombie = newZombie("donghyle");
	zombie->announce();
	delete zombie;
	zombie = newZombie("seonjeon");
	zombie->announce();
	delete zombie;
	return (0);
}
