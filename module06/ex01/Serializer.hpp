#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class	Serializer
{
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

private:
						Serializer(void);
						Serializer(const Serializer &orig);
						~Serializer(void);
	Serializer			&operator=(const Serializer &orig);
};

#endif
