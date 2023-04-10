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
	char				valChar;
	int					valInt;
	float				valFloat;
	double				valDouble;
	std::stringstream	buf;

	#ifdef _DEBUG
	std::cout << "Literal type is #" << detectLiteralType(str) << "\n";
	#endif
	switch (detectLiteralType(str))
	{
	case LITERAL_NONE:
		convertNone();
		break;
	case LITERAL_CHAR:
		valChar = str[0];
		std::cout << "char: " << valChar << "\n";
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(int, char, valChar);
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(float, char, valChar);
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(double, char, valChar);
		break;
	case LITERAL_INT:
		buf.str(str);
		buf >> valInt;
		if (buf.fail())
		{
			ScalarConverter::convertNone();
			return ;
		}
		TRY_CAST_PRINT_CHAR(char, int, valInt);
		std::cout << "int: " << valInt << "\n";
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(float, int, valInt);
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(double, int, valInt);
		break;
	case LITERAL_FLOAT:
		if (isExtremeFloat(str))
			valFloat = convertExtremeFloat(str);
		else
		{
			buf.str(str.substr(0, str.length() - 1));
			buf >> valFloat;
			if (buf.fail())
			{
				ScalarConverter::convertNone();
				return ;
			}
		}
		TRY_CAST_PRINT_CHAR(char, float, valFloat);
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(int, float, valFloat);
		std::cout << "float: " << valFloat << "\n";
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(double, float, valFloat);
		break;
	case LITERAL_DOUBLE:
		if (isExtremeDouble(str))
			valDouble = convertExtremeDouble(str);
		else
		{
			buf.str(str);
			buf >> valDouble;
			if (buf.fail())
			{
				ScalarConverter::convertNone();
				return ;
			}
		}
		TRY_CAST_PRINT_CHAR(char, double, valDouble);
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(int, double, valDouble);
		TRY_CAST_PRINT_INT_FLOAT_DOUBLE(float, double, valDouble);
		std::cout << "double: " << valDouble << "\n";
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
