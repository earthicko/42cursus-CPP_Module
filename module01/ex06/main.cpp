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
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	n = Harl::getLevelIndex(argv[1]);
	switch (n)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
