#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "identify.hpp"
#include <iostream>

void	identify(Base *p)
{
	IDENTIFY_POINTER(Base, A, p);
	IDENTIFY_POINTER(Base, B, p);
	IDENTIFY_POINTER(Base, C, p);
}

void	identify(Base &p)
{
	IDENTIFY_REFERENCE(Base, A, p);
	IDENTIFY_REFERENCE(Base, B, p);
	IDENTIFY_REFERENCE(Base, C, p);
}
