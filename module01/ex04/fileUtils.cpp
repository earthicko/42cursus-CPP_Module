#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "fileUtils.hpp"

std::string	openFileToString(t_pchar path)
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

std::string	replaceOccurence(t_strref content, t_pchar s1, t_pchar s2)
{
	const std::string	orig(s1);
	const std::string	replace(s2);
	std::string			result;
	size_t				pos;
	size_t				start;

	if (strlen(s1) == 0)
	{
		std::cout << "Length of s1 cannot be 0" << std::endl;
		exit(1);
	}
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

void	writeStringToFile(t_strref path, t_strref content)
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
