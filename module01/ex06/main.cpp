#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl				harl;
	std::string			level;
	int					n;
	const std::string	levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	if (argc <= 1)
	{
		std::cout << "Usage: harlFilter <level>" << std::endl;
		return (2);
	}
	level = argv[1];
	harl.setComplaintLevel(level);
	srand(time(NULL));
	std::cout << "Number of complaints: ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
		harl.complain(levels[rand() % 4]);
	return (0);
}
