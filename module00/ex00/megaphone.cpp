#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	argv++;
	while (*argv)
	{
		std::string word = *argv;
		for (std::string::iterator it = word.begin(); it != word.end(); it++)
			*it = toupper(*it);
		std::cout << word;
		argv++;
		if (*argv)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}
