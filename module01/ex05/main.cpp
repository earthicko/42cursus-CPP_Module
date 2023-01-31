#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Harl.hpp"

int	main(void)
{
	Harl				harl;
	int					n;
	const std::string	levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	srand(time(NULL));
	std::cout << "Number of complaints: ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
		harl.complain(levels[rand() % 4]);
	return (0);
}
