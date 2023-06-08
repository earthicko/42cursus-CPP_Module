#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	argv++;
	while (*argv)
	{
		RPN rpn;
		std::stringstream buf;
		std::string word;

		buf.str(*argv);
		try
		{
			while (!buf.eof())
			{
				std::getline(buf, word, ' ');
				if (word.length() < 1)
					continue;
				rpn.process(word);
			}
			std::cout << rpn.result() << "\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		argv++;
	}
	return (0);
}
