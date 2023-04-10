#include "BitcoinExchange.hpp"
#include <iostream>

void	process(const BitcoinExchange &bx, const std::string &filepath)
{
	std::cout << "Unimplemented stub of " << __func__ << "\n";
	(void)bx;
	(void)filepath;
}

int	main(int argc, char **argv)
{
	BitcoinExchange	bx;

	if (argc != 2)
		return (1);
	process(bx, argv[1]);
	return (0);
}
