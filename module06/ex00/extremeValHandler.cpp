#include <limits>
#include <string>
#include <exception>

bool	isExtremeFloat(const std::string &str)
{
	return (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf");
}

bool	isExtremeDouble(const std::string &str)
{
	return (str == "-inf" || str == "+inf" || str == "inf" || str == "nan");
}

bool	isExtremeVal(const float &val)
{
	return (val != val
		|| val == -(std::numeric_limits<float>::infinity())
		|| val == +(std::numeric_limits<float>::infinity()));
}

bool	isExtremeVal(const double &val)
{
	return (val != val
		|| val == -(std::numeric_limits<double>::infinity())
		|| val == +(std::numeric_limits<double>::infinity()));
}

float	convertExtremeFloat(const std::string &str)
{
	if (str == "-inff")
		return (-(std::numeric_limits<float>::infinity()));
	if (str == "+inff")
		return (+(std::numeric_limits<float>::infinity()));
	if (str == "inff")
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
	if (str == "inf")
		return (+(std::numeric_limits<double>::infinity()));
	if (str == "nan")
		return (std::numeric_limits<double>::quiet_NaN());
	throw (std::runtime_error("Given string is not extreme double representation."));
}

std::string	extremeValToString(const float &val)
{
	if (val != val)
		return (std::string("nanf"));
	if (val == -(std::numeric_limits<float>::infinity()))
		return (std::string("-inff"));
	if (val == +(std::numeric_limits<float>::infinity()))
		return (std::string("inff"));
	throw (std::runtime_error("Given float is not extreme float."));
}

std::string	extremeValToString(const double &val)
{
	if (val != val)
		return (std::string("nan"));
	if (val == -(std::numeric_limits<double>::infinity()))
		return (std::string("-inf"));
	if (val == +(std::numeric_limits<double>::infinity()))
		return (std::string("inf"));
	throw (std::runtime_error("Given double is not extreme double."));
}
