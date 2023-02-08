#include <iostream>
#include <string>

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
		for (size_t i = 0; i < word.size(); i++)
			word[i] = toupper(word[i]);
		std::cout << word;
		argv++;
		if (*argv)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}
