#include <string>

bool	isLiteralChar(const std::string& str)
{
	return (str.length() == 1);
}

bool	isLiteralInt(const std::string& str)
{
	if (str.length() < 1)
		return (false);
	if (str.length() == 1)
		return (isdigit(str[0]));
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			continue ;
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue ;
		else
			return (false);
	}
	return (true);
}

bool	isLiteralFloat(const std::string& str)
{
	int	decimalCount;
	int	digitCount;
	int	floatIndicatorCount;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	decimalCount = 0;
	digitCount = 0;
	floatIndicatorCount = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			digitCount++;
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue ;
		else if (i == str.length() - 1 && str[i] == 'f')
			floatIndicatorCount++;
		else if (str[i] == '.')
		{
			if (digitCount == 0)
				return (false);
			if (i == str.length() - 2)
				return (false);
			decimalCount++;
		}
		else
			return (false);
	}
	return (decimalCount == 1 && digitCount >= 2 && floatIndicatorCount == 1);
}

bool	isLiteralDouble(const std::string& str)
{
	int	decimalCount;
	int	digitCount;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	decimalCount = 0;
	digitCount = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			digitCount++;
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue ;
		else if (str[i] == '.')
		{
			if (digitCount == 0)
				return (false);
			if (i == str.length() - 1)
				return (false);
			decimalCount++;
		}
		else
			return (false);
	}
	return (decimalCount == 1 && digitCount >= 2);
}
