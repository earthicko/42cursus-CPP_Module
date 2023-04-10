#include "BitcoinExchange.hpp"
#include <iostream>

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
	std::cout << "Unimplemented stub of " << __func__ << "\n";
	std::cout << "filepath " << filepath << "\n";
}
