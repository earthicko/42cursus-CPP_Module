#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <string>

static void	convertIntToChar(int val)
{
	char	casted;

	casted = static_cast<char>(val);
	if (static_cast<int>(casted) != val)
	{
		std::cout << "char: impossible\n";
		return ;
	}
	if (isprint(casted))
		std::cout << "char: '" << casted << "'\n";
	else
		std::cout << "char: Non displayable\n";
}

static void	convertIntToFloat(int val)
{
	float	casted;

	casted = static_cast<float>(val);
	if (static_cast<int>(casted) != val)
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << casted << "\n";
}

static void	convertIntToDouble(int val)
{
	double	casted;

	casted = static_cast<double>(val);
	if (static_cast<int>(casted) != val)
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << casted << "\n";
}

void	ScalarConverter::convertInt(const std::string& str)
{
	int					val;
	std::stringstream	buf;

	buf.str(str);
	buf >> val;
	if (buf.fail())
	{
		ScalarConverter::convertNone();
		return ;
	}
	convertIntToChar(val);
	std::cout << "int: " << val << "\n";
	convertIntToFloat(val);
	convertIntToDouble(val);
}
