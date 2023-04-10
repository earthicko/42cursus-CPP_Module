#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <string>

static void	convertFloatToChar(float val)
{
	char	casted;

	casted = static_cast<char>(val);
	if (static_cast<float>(casted) != val)
	{
		std::cout << "char: impossible\n";
		return ;
	}
	if (isprint(casted))
		std::cout << "char: '" << casted << "'\n";
	else
		std::cout << "char: Non displayable\n";
}

static void	convertFloatToInt(float val)
{
	int	casted;

	casted = static_cast<int>(val);
	if (static_cast<float>(casted) != val)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << casted << "\n";
}

static void	convertFloatToDouble(float val)
{
	double	casted;

	casted = static_cast<double>(val);
	if (static_cast<float>(casted) != val)
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << casted << "\n";
}

void	ScalarConverter::convertFloat(const std::string& str)
{
	float				val;
	std::stringstream	buf;

	// if (isExtremeFloat(str))
	// 	valFloat = convertExtremeFloat(str);
	buf.str(str.substr(0, str.length() - 1));
	buf >> val;
	if (buf.fail())
	{
		ScalarConverter::convertNone();
		return ;
	}
	convertFloatToChar(val);
	convertFloatToInt(val);
	std::cout << "float: " << val << "\n";
	convertFloatToDouble(val);
}
