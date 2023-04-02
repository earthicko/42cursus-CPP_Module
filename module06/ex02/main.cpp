#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*generate(void)
{
	switch (std::rand() % 3)
	{
	case 0:
		std::cout << "Generated class object A\n";
		return (new A());
		break;
	case 1:
		std::cout << "Generated class object B\n";
		return (new B());
		break;
	case 2:
		std::cout << "Generated class object C\n";
		return (new C());
		break;
	default:
		break;
	}
	return (NULL);
}

int	main(void)
{
	Base	*randomObjPtr;

	std::srand(std::time(0));
	randomObjPtr = generate();
	identify(randomObjPtr);
	identify(*randomObjPtr);
	delete randomObjPtr;
	return (0);
}
