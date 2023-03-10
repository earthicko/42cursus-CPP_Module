#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieUtils.hpp"

int	main(int argc, char **argv)
{
	Zombie	*zombies;
	int		n;

	n = 1;
	if (argc > 1)
		n = atoi(argv[1]);
	zombies = zombieHorde(n, "donghyle");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	system("leaks ex01");
	return (0);
}
