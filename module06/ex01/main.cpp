#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>
#include <iostream>

void	printData(Data data)
{
	std::cout << "Data len " << data.len << ", content = {";
	for (int i = 0; i < data.len; i++)
	{
		std::cout << data.buf[i];
		if (i < data.len - 1)
			std::cout << ", ";
	}
	std::cout << "}\n";
}

int	main(void)
{
	Data		data;
	uintptr_t	serialized;
	Data		*deserialized;

	data.len = 5;
	for (int i = 0; i < data.len; i++)
		data.buf[i] = 1 << i;
	serialized = Serializer::serialize(&data);
	deserialized = Serializer::deserialize(serialized);
	std::cout << "Orig addr: " << &data << "\n";
	std::cout << "Serialized: " << serialized << "\n";
	std::cout << "Deserialized: " << deserialized << "\n";
	std::cout << "Orig: ";
	printData(data);
	std::cout << "Deserialized: ";
	printData(*deserialized);
	return (0);
}
