#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

const std::string	BitcoinExchange::_firstColumn = "date";
const std::string	BitcoinExchange::_secondColumn = "exchange_rate";
const char			BitcoinExchange::_delim = ',';
const std::string	BitcoinExchange::_dateFormat = "%Y-%m-%d";

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

float	BitcoinExchange::getPrice(time_t at) const
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
		std::string			line;
		std::stringstream	buf;
		std::string			date;
		std::string			price;

		std::getline(file, line);
		if (line.find(_delim) == std::string::npos)
			break ;
		buf.str(line);
		std::getline(buf, date, _delim);
		std::getline(buf, price, _delim);
		if (lineidx == 0 && !(date == _firstColumn && price == _secondColumn))
			throw (std::runtime_error("Invalid first line"));
		if (lineidx > 0)
			loadLine(date, price);
		lineidx++;
	}
}

static time_t	parseDate(const std::string &date, const std::string &format)
{
	tm		dateVal;
	time_t	epoch;
	char	*result;

	memset(&dateVal, 0, sizeof(tm));
	result = strptime(date.c_str(), format.c_str(), &dateVal);
	epoch = mktime(&dateVal);
	if (!result || epoch < 0)
		throw (std::runtime_error(std::string("Invalid date ") + date));
	return (epoch);
}

static float	parsePrice(const std::string &price)
{
	std::stringstream	buf;
	float				priceVal;

	buf.str(price);
	buf >> priceVal;
	if (buf.fail())
		throw (std::runtime_error(std::string("Invalid price ") + price));
	return (priceVal);
}

void	BitcoinExchange::loadLine(const std::string &date, const std::string &price)
{
	time_t	dateVal;
	float	priceVal;

	dateVal = parseDate(date, _dateFormat);
	priceVal = parsePrice(price);
	if (_prices.find(dateVal) != _prices.end())
		std::cerr << "Warning: multiple price values at date " << date << "\n";
	_prices[dateVal] = priceVal;
}
