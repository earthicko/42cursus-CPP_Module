#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void	printPriceAt(const BitcoinExchange &bx, const std::string &date, const std::string &amount)
{
	time_t	dateVal;
	float	amountVal;
	float	price;

	dateVal = bx.parseDate(date);
	amountVal = bx.parseNumber(amount);
	price = bx.getPrice(dateVal);
}

void	processLine(const BitcoinExchange &bx, std::ifstream &file)
{
	std::string			line;
	std::stringstream	buf;
	std::string			first;
	std::string			delim;
	std::string			second;

	std::getline(file, line);
	buf.str(line);
	buf >> first;
	buf >> delim;
	buf >> second;
	if (delim != "|" || first.length() == 0 || second.length() == 0)
		throw (std::runtime_error(std::string("Invalid line ") + line));
	printPriceAt(bx, first, second);
}

void	process(const BitcoinExchange &bx, const std::string &filepath)
{
	std::ifstream	file;

	file.open(filepath, std::ios_base::in);
	if (!file.is_open())
		throw (std::ifstream::failure(std::string("Failed to open ") + filepath));
	while (!file.eof())
	{
		try
		{
			processLine(bx, file);
		}
		catch (const std::runtime_error &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int	main(int argc, char **argv)
{
	BitcoinExchange	bx;

	if (argc != 2)
		return (1);
	process(bx, argv[1]);
	return (0);
}
