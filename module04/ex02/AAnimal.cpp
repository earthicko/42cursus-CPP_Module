#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal: Destructor\n";
}

const std::string	&AAnimal::getType(void) const
{
	return (type);
}
