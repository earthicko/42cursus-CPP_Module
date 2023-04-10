#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <limits.h>
# include <sstream>
# include <iostream>

class	ScalarConverter
{
	public:
		static void		convert(const std::string& str);

	private:
						ScalarConverter(void);
						ScalarConverter(const ScalarConverter &orig);
						~ScalarConverter(void);
		ScalarConverter	&operator=(const ScalarConverter &orig);

		static int		detectLiteralType(const std::string& str);
		static void		convertNone(void);
		static void		convertChar(const std::string& str);
		static void		convertInt(const std::string& str);
		static void		convertFloat(const std::string& str);
		static void		convertDouble(const std::string& str);

		enum literal_e
		{
			LITERAL_NONE = 0,
			LITERAL_CHAR,
			LITERAL_INT,
			LITERAL_FLOAT,
			LITERAL_DOUBLE,
		};
};

bool		isExtremeFloat(const std::string &str);
bool		isExtremeDouble(const std::string &str);
bool		isExtremeVal(const float &val);
bool		isExtremeVal(const double &val);
float		convertExtremeFloat(const std::string &str);
double		convertExtremeDouble(const std::string &str);
std::string	extremeValToString(const float &val);
std::string	extremeValToString(const double &val);

bool		isLiteralChar(const std::string& str);
bool		isLiteralInt(const std::string& str);
bool		isLiteralFloat(const std::string& str);
bool		isLiteralDouble(const std::string& str);

#endif
