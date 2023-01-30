#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain		= "HI THIS IS BRAIN";
	std::string	*stringPTR	= &brain;
	std::string	&stringREF	= brain;

	std::cout << "Address      : string   : " << &brain << std::endl;
	std::cout << "Value        : stringPTR: " << stringPTR << std::endl;
	std::cout << "Value        : stringREF: " << &stringREF << std::endl;
	std::cout << "Value        : string   : " << brain << std::endl;
	std::cout << "Value Pointed: stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value Pointed: stringREF: " << stringREF << std::endl;
	return (0);
}
