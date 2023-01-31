#include <iostream>
#include <string>
#include "Harl.hpp"

void	(Harl::*(Harl::loggers)[4])(void) =
{
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

std::string	(Harl::loggernames)[4] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

Harl::Harl(void)
{
}

Harl::Harl(const Harl &orig)
{
	(void)orig;
}

Harl::~Harl(void)
{
}

Harl	&Harl::operator=(const Harl &orig)
{
	(void)orig;
	return (*this);
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < nLoggers; i++)
	{
		if (loggernames[i] == level)
		{
			(this->*loggers[i])();
			return ;
		}
	}
	std::cout << "Unimplemented log level." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas ";
	std::cout << "you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}
