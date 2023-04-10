#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <string>

static void	convertDoubleToChar(double val)
{
	char	casted;

	casted = static_cast<char>(val);
	if (static_cast<double>(casted) != val)
	{
		std::cout << "char: impossible\n";
		return ;
	}
	if (isprint(casted))
		std::cout << "char: '" << casted << "'\n";
	else
		std::cout << "char: Non displayable\n";
}

static void	convertDoubleToInt(double val)
{
	int	casted;

	casted = static_cast<int>(val);
	if (static_cast<double>(casted) != val)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << casted << "\n";
}

static void	convertDoubleToFloat(double val)
{
	float	casted;

	casted = static_cast<float>(val);
	if (static_cast<double>(casted) != val)
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << casted << "\n";
}

void	ScalarConverter::convertDouble(const std::string& str)
{
	double				val;
	std::stringstream	buf;

	// if (isExtremeDouble(str))
	// 	valDouble = convertExtremeDouble(str);
	buf.str(str);
	buf >> val;
	if (buf.fail())
	{
		ScalarConverter::convertNone();
		return ;
	}
	convertDoubleToChar(val);
	convertDoubleToInt(val);
	convertDoubleToFloat(val);
	std::cout << "double: " << val << "\n";
}
