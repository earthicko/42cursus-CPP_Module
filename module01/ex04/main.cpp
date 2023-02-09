#include <iostream>
#include <string>
#include "fileUtils.hpp"

int	main(int argc, char **argv)
{
	std::string	content;
	std::string	newContent;
	std::string	newPath;

	if (argc != 1 + 3)
	{
		std::cout << "Usage: ./ex04 filename s1 s2" << std::endl;
		return (2);
	}
	content = openFileToString(argv[1]);
	newContent = replaceOccurence(content, argv[2], argv[3]);
	newPath = argv[1];
	newPath = newPath.append(".replace");
	writeStringToFile(newPath, newContent);
	return (0);
}
