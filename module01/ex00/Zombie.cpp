#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string new_name):
	name(new_name)
{
}

Zombie::~Zombie(void)
{
	std::cout << name << ": deleted" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
