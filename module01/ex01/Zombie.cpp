#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(const Zombie &zombie):
	name(zombie.name)
{
}

Zombie::~Zombie(void)
{
	std::cout << name << ": deleted" << std::endl;
}

Zombie	&Zombie::operator=(const Zombie &zombie)
{
	name = zombie.name;
	return (*this);
}

Zombie::Zombie(std::string new_name):
	name(new_name)
{
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
