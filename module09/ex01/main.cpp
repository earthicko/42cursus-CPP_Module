#include "RPN.hpp"
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	argv++;
	while (*argv)
	{
		RPN					rpn;
		std::stringstream	buf;
		std::string			word;

		buf.str(*argv);
		try
		{
			while (!buf.eof())
			{
				buf >> word;
				rpn.process(word);
			}
			std::cout << rpn.result() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		argv++;
	}
	return (0);
}
