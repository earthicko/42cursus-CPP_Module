#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

# include "Base.hpp"
# include <iostream>

# define IDENTIFY_POINTER(BASET, DERIVEDT, PTR)								\
	{																		\
		DERIVEDT	*derivedptr;											\
																			\
		derivedptr = dynamic_cast<DERIVEDT *>(PTR);							\
		if (derivedptr != nullptr)											\
			std::cout << "Pointer of class object " << #DERIVEDT << "\n";	\
	}

# define IDENTIFY_REFERENCE(BASET, DERIVEDT, OBJECT)						\
	{																		\
		bool		didCast;												\
		BASET	&baseref = OBJECT;											\
																			\
		didCast = true;														\
		try																	\
		{																	\
			DERIVEDT	&derivedref = dynamic_cast<DERIVEDT &>(baseref);	\
			(void)derivedref;												\
		}																	\
		catch(const std::exception& e)										\
		{																	\
			didCast = false;												\
		}																	\
		if (didCast)														\
			std::cout << "Reference of class object " << #DERIVEDT << "\n";	\
	}

void	identify(Base *p);
void	identify(Base &p);

#endif
