#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombie;

	zombie = Zombie(name);
	zombie.announce();
}
