#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

const std::string firstColumn = "date";
const std::string secondColumn = "value";

void trimSpace(std::string &s)
{
	size_t end = s.find_last_not_of(" ");
	if (end == std::string::npos)
	{
		s = "";
		return;
	}
	s = s.substr(0, end + 1);
	size_t start = s.find_first_not_of(" ");
	if (start == std::string::npos)
	{
		s = "";
		return;
	}
	s = s.substr(start);
}

void printPriceAt(const BitcoinExchange &bx, const std::string &date, const std::string &amount)
{
	time_t dateVal;
	float amountVal;
	float price;
	float totalPrice;

	dateVal = bx.parseDate(date);
	amountVal = bx.parseNumber(amount);
	if (amountVal < 0 || amountVal > 1000)
	{
		std::stringstream buf;

		buf << "value " << amountVal << " is out of bound.";
		throw(std::runtime_error(buf.str()));
	}
	price = bx.getPrice(dateVal);
	totalPrice = amountVal * price;
	std::cout << date << ": " << amountVal << " * " << price << " = " << totalPrice << "\n";
}

void processLine(const BitcoinExchange &bx, std::ifstream &file)
{
	std::string line;
	std::stringstream buf;
	std::string first;
	std::string second;
	const char delim = '|';

	std::getline(file, line);
	if (line == "")
		return;
	buf.str(line);
	std::getline(buf, first, delim);
	std::getline(buf, second, delim);
	if (first.length() == 0 || second.length() == 0 || !buf.eof())
		throw(std::runtime_error(std::string("Invalid line ") + line));
	trimSpace(first);
	trimSpace(second);
	if (first == firstColumn && second == secondColumn)
		return;
	printPriceAt(bx, first, second);
}

void process(const BitcoinExchange &bx, const std::string &filepath)
{
	std::ifstream file;
	std::ios_base::fmtflags saved_flags;

	file.open(filepath.c_str(), std::ios_base::in);
	if (!file.is_open())
		throw(std::ifstream::failure(std::string("Failed to open ") + filepath));
	saved_flags = std::cout.flags();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(std::numeric_limits<float>::digits10);
	while (!file.eof())
	{
		try
		{
			processLine(bx, file);
		}
		catch (const std::runtime_error &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout.flags(saved_flags);
}

int main(int argc, char **argv)
{
	BitcoinExchange bx;

	if (!bx.isLoaded())
		return (1);
	if (argc != 2)
		return (1);
	try
	{
		process(bx, argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
