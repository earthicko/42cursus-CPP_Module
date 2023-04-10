#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int	ScalarConverter::detectLiteralType(const std::string& str)
{
	if (isLiteralFloat(str))
		return (LITERAL_FLOAT);
	if (isLiteralDouble(str))
		return (LITERAL_DOUBLE);
	if (isLiteralInt(str))
		return (LITERAL_INT);
	if (isLiteralChar(str))
		return (LITERAL_CHAR);
	return (LITERAL_NONE);
}

void	ScalarConverter::convertNone(void)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

void	ScalarConverter::convert(const std::string& str)
{
	#ifdef _DEBUG
	std::cout << "Literal type is #" << detectLiteralType(str) << "\n";
	#endif
	switch (detectLiteralType(str))
	{
	case LITERAL_NONE:
		convertNone();
		break;
	case LITERAL_CHAR:
		convertChar(str);
		break;
	case LITERAL_INT:
		convertInt(str);
		break;
	case LITERAL_FLOAT:
		convertFloat(str);
		break;
	case LITERAL_DOUBLE:
		convertDouble(str);
		break;
	default:
		break;
	}
}

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &orig)
{
	(void)orig;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &orig)
{
	(void)orig;
	return (*this);
}
