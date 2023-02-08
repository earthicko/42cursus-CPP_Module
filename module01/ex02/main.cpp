#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain		= "HI THIS IS BRAIN";
	std::string	*stringPTR	= &brain;
	std::string	&stringREF	= brain;

	std::cout << "Address of string         : " << &brain << std::endl;
	std::cout << "Value of stringPTR        : " << stringPTR << std::endl;
	std::cout << "Address of stringREF      : " << &stringREF << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
	return (0);
}
