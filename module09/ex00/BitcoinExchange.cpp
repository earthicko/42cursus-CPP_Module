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
	: _isLoaded(false)
{
	try
	{
		load(filepath);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig)
	: _isLoaded(false)
{
	_prices = orig._prices;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &orig)
{
	_prices = orig._prices;
	_isLoaded = orig._isLoaded;
	return (*this);
}

float	BitcoinExchange::getPrice(time_t at) const
{
	if (!_isLoaded)
		throw (std::runtime_error("Dataset is not loaded."));
	std::map<time_t, float>::const_iterator bound = _prices.upper_bound(at);
	if (bound == _prices.begin() && at < bound->first)
		throw (std::runtime_error("date is prior to the earliest date in data"));
	bound--;
	return (bound->second);
}

bool	BitcoinExchange::isLoaded(void) const
{
	return (_isLoaded);
}

void	BitcoinExchange::load(const std::string &filepath)
{
	std::ifstream	file;
	int				lineidx;

	file.open(filepath.c_str(), std::ios_base::in);
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
	_isLoaded = true;
}

time_t	BitcoinExchange::parseDate(const std::string &date)
{
	tm		dateVal;
	time_t	epoch;
	char	*result;

	memset(&dateVal, 0, sizeof(tm));
	result = strptime(date.c_str(), _dateFormat.c_str(), &dateVal);
	epoch = mktime(&dateVal);
	if (!result || epoch < 0)
		throw (std::runtime_error(std::string("Invalid date ") + date));
	return (epoch);
}

float	BitcoinExchange::parseNumber(const std::string &number)
{
	std::stringstream	buf;
	float				priceVal;

	buf.str(number);
	buf >> priceVal;
	if (buf.fail())
		throw (std::runtime_error(std::string("Invalid number ") + number));
	return (priceVal);
}

void	BitcoinExchange::loadLine(const std::string &date, const std::string &price)
{
	time_t	dateVal;
	float	priceVal;

	dateVal = parseDate(date);
	priceVal = parseNumber(price);
	if (_prices.find(dateVal) != _prices.end())
		std::cerr << "Warning: multiple price values at date " << date << "\n";
	_prices[dateVal] = priceVal;
}
