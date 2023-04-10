#include <limits>
#include <string>
#include <exception>

bool	isExtremeFloat(const std::string &str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf");
}

bool	isExtremeDouble(const std::string &str)
{
	return (str == "-inf" || str == "+inf" || str == "nan");
}

float	convertExtremeFloat(const std::string &str)
{
	if (str == "-inff")
		return (-(std::numeric_limits<float>::infinity()));
	if (str == "+inff")
		return (+(std::numeric_limits<float>::infinity()));
	if (str == "nanf")
		return (std::numeric_limits<float>::quiet_NaN());
	throw (std::runtime_error("Given string is not extreme float representation."));
}

double	convertExtremeDouble(const std::string &str)
{
	if (str == "-inf")
		return (-(std::numeric_limits<double>::infinity()));
	if (str == "+inf")
		return (+(std::numeric_limits<double>::infinity()));
	if (str == "nan")
		return (std::numeric_limits<double>::quiet_NaN());
	throw (std::runtime_error("Given string is not extreme double representation."));
}
