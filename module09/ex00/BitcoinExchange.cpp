#include "BitcoinExchange.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

const std::string BitcoinExchange::_firstColumn = "date";
const std::string BitcoinExchange::_secondColumn = "exchange_rate";
const char BitcoinExchange::_delim = ',';

BitcoinExchange::BitcoinExchange(const std::string &filepath)
	: _isLoaded(false)
{
	try
	{
		load(filepath);
	}
	catch (const std::exception &e)
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

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &orig)
{
	_prices = orig._prices;
	_isLoaded = orig._isLoaded;
	return (*this);
}

float BitcoinExchange::getPrice(time_t at) const
{
	if (!_isLoaded)
		throw(std::runtime_error("Dataset is not loaded."));
	std::map<time_t, float>::const_iterator bound = _prices.upper_bound(at);
	if (bound == _prices.begin() && at < bound->first)
		throw(std::runtime_error("date is prior to the earliest date in data"));
	bound--;
	return (bound->second);
}

bool BitcoinExchange::isLoaded(void) const
{
	return (_isLoaded);
}

void BitcoinExchange::load(const std::string &filepath)
{
	std::ifstream file;
	int lineidx;

	file.open(filepath.c_str(), std::ios_base::in);
	if (!file.is_open())
		throw(std::ifstream::failure(std::string("Failed to open ") + filepath));
	lineidx = 0;
	while (!file.eof())
	{
		std::string line;
		std::stringstream buf;
		std::string date;
		std::string price;

		std::getline(file, line);
		if (line.find(_delim) == std::string::npos)
			break;
		buf.str(line);
		std::getline(buf, date, _delim);
		std::getline(buf, price, _delim);
		if (!buf.eof())
			throw(std::runtime_error("Invalid line " + line));
		if (lineidx == 0 && !(date == _firstColumn && price == _secondColumn))
			throw(std::runtime_error("Invalid first line " + line));
		if (lineidx > 0)
			loadLine(date, price);
		lineidx++;
	}
	_isLoaded = true;
}

int parseString(const std::string &str)
{
	std::stringstream buf;
	int val;

	buf.str(str);
	buf >> val;
	if (buf.fail())
		throw(std::runtime_error(std::string("Invalid token ") + str));
	return (val);
}

time_t BitcoinExchange::parseDate(const std::string &date)
{
	tm dateVal;
	tm normalizedDateVal;
	time_t epoch;

	memset(&dateVal, 0, sizeof(tm));
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw(std::runtime_error(std::string("Invalid date ") + date));
	dateVal.tm_year = parseString(date.substr(0, 4)) - 1900;
	dateVal.tm_mon = parseString(date.substr(5, 7)) - 1;
	dateVal.tm_mday = parseString(date.substr(8, 10));
	normalizedDateVal = dateVal;
	epoch = mktime(&normalizedDateVal);
	if (epoch < 0 || dateVal.tm_year != normalizedDateVal.tm_year || dateVal.tm_mon != normalizedDateVal.tm_mon
		|| dateVal.tm_mday != normalizedDateVal.tm_mday)
		throw(std::runtime_error(std::string("Invalid date ") + date));
	return (epoch);
}

float BitcoinExchange::parseNumber(const std::string &number)
{
	std::stringstream buf;
	float priceVal;

	buf.str(number);
	buf >> priceVal;
	if (buf.fail())
		throw(std::runtime_error(std::string("Invalid number ") + number));
	return (priceVal);
}

void BitcoinExchange::loadLine(const std::string &date, const std::string &price)
{
	time_t dateVal;
	float priceVal;

	dateVal = parseDate(date);
	priceVal = parseNumber(price);
	if (_prices.find(dateVal) != _prices.end())
		std::cerr << "Warning: multiple price values at date " << date << "\n";
	_prices[dateVal] = priceVal;
}
