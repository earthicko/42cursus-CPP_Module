#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <limits.h>
# include <sstream>
# include <iostream>

# define TRY_CAST_PRINT(TYPE_TARGET, TYPE_ORIGIN, VALUE)					\
	try																		\
	{																		\
		TYPE_TARGET casted = static_cast<TYPE_TARGET>(VALUE);				\
		if (static_cast<TYPE_ORIGIN>(casted) != VALUE)						\
			throw std::runtime_error("Impossible value to represent");		\
		if (std::is_same<TYPE_TARGET, char>::value)							\
		{																	\
			if (isprint(VALUE))												\
				std::cout << #TYPE_TARGET << ": '" << casted << "'\n";		\
			else															\
				std::cout << #TYPE_TARGET << ": Non displayable\n";			\
		}																	\
		else																\
			std::cout << #TYPE_TARGET << ": " << casted << "\n";			\
	}																		\
	catch(const std::exception& e)											\
	{																		\
		(void)e;															\
		std::cout << #TYPE_TARGET << ": impossible\n";						\
	}

# define CONVERT_TO_ALL_TYPES(TYPE, STR)									\
	{																		\
		TYPE				converted;										\
		std::stringstream	buf;											\
																			\
		if (std::is_same<TYPE, char>::value)								\
		{																	\
			converted = STR[0];												\
		}																	\
		else																\
		{																	\
			if (std::is_same<TYPE, float>::value)							\
				buf.str(STR.substr(0, STR.length() - 1));					\
			else															\
				buf.str(STR);												\
			buf >> converted;												\
		}																	\
		if (!std::is_same<TYPE, char>::value && buf.fail())					\
			ScalarConverter::convertNone();									\
		else																\
		{																	\
			TRY_CAST_PRINT(char, TYPE, converted);							\
			TRY_CAST_PRINT(int, TYPE, converted);							\
			TRY_CAST_PRINT(float, TYPE, converted);							\
			TRY_CAST_PRINT(double, TYPE, converted);						\
		}																	\
	}

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

		enum literal_e
		{
			LITERAL_NONE = 0,
			LITERAL_CHAR,
			LITERAL_INT,
			LITERAL_FLOAT,
			LITERAL_DOUBLE,
		};
};

bool	isLiteralChar(const std::string& str);
bool	isLiteralInt(const std::string& str);
bool	isLiteralFloat(const std::string& str);
bool	isLiteralDouble(const std::string& str);

#endif
