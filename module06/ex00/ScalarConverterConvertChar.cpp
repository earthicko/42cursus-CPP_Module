#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

static void	convertCharToInt(char val)
{
	int	casted;

	casted = static_cast<int>(val);
	if (static_cast<char>(casted) != val)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << casted << "\n";
}

static void	convertCharToFloat(char val)
{
	float	casted;

	casted = static_cast<float>(val);
	if (static_cast<char>(casted) != val)
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << casted << "\n";
}

static void	convertCharToDouble(char val)
{
	double	casted;

	casted = static_cast<double>(val);
	if (static_cast<char>(casted) != val)
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << casted << "\n";
}

void	ScalarConverter::convertChar(const std::string& str)
{
	char	val;

	val = str[0];
	std::cout << "char: '" << val << "'\n";
	convertCharToInt(val);
	convertCharToFloat(val);
	convertCharToDouble(val);
}
