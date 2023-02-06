#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string	openFileToString(char *path)
{
	std::ifstream		infile;
	std::stringstream	buffer;

	infile.open(path, std::ios::in);
	if (!infile.good())
	{
		std::cout << "Error while opening " << path << std::endl;
		exit(1);
	}
	buffer << infile.rdbuf();
	infile.close();
	return buffer.str();
}

std::string	replaceOccurence(const std::string &content, char *s1, char *s2)
{
	std::string	orig;
	std::string	replace;
	std::string	result;
	size_t		pos;
	size_t		start;

	if (strlen(s1) == 0)
	{
		std::cout << "Length of s1 cannot be 0" << std::endl;
		exit(1);
	}
	orig = s1;
	replace = s2;
	start = 0;
	while (true)
	{
		pos = content.find(orig, start);
		if (pos == std::string::npos)
		{
			result += content.substr(start);
			break ;
		}
		result += content.substr(start, pos - start) + replace;
		start = pos + orig.length();
	}
	return (result);
}

void	writeStringToFile(const std::string &path, const std::string &content)
{
	std::ofstream out(path.c_str(), std::ios::out);
	if (!out.good())
	{
		std::cout << "Error while opening " << path << std::endl;
		exit(1);
	}
	out << content;
	out.close();
}

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
