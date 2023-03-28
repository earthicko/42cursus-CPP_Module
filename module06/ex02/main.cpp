#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "identify.hpp"
#include <random>
#include <iostream>

Base	*generate(void)
{
	std::random_device	rd;

	switch (rd() % 3)
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
	return (nullptr);
}

int	main(void)
{
	Base	*randomObjPtr;

	randomObjPtr = generate();
	identify(randomObjPtr);
	identify(*randomObjPtr);
	delete randomObjPtr;
	return (0);
}
