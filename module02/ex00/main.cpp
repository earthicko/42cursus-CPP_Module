#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	mosCode;
	Fixed	serviceNum(mosCode);
	Fixed	firearmSerial;

	firearmSerial = serviceNum;
	std::cout << mosCode.getRawBits() << std::endl;
	std::cout << serviceNum.getRawBits() << std::endl;
	std::cout << firearmSerial.getRawBits() << std::endl;

	mosCode.setRawBits(17110);
	serviceNum.setRawBits(18 - 70002666);
	firearmSerial.setRawBits(1331909);

	std::cout << mosCode.getRawBits() << std::endl;
	std::cout << serviceNum.getRawBits() << std::endl;
	std::cout << firearmSerial.getRawBits() << std::endl;

	return 0;
}
