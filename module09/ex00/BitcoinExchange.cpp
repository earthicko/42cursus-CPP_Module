#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange(const std::string &filepath)
{
	load(filepath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig)
{
	_prices = orig._prices;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &orig)
{
	_prices = orig._prices;
	return (*this);
}

float	BitcoinExchange::getPrice(time_t at)
{
	std::cout << "Unimplemented stub of " << __func__ << "\n";
	std::cout << "time " << at << "\n";
	return (0.0f);
}

void	BitcoinExchange::load(const std::string &filepath)
{
	std::ifstream	file;
	int				lineidx;

	file.open(filepath, std::ios_base::in);
	if (!file.is_open())
		throw (std::ifstream::failure(std::string("Failed to open ") + filepath));
	lineidx = 0;
	while (!file.eof())
	{
		std::string	buf;

		std::getline(file, buf);
	}
}
