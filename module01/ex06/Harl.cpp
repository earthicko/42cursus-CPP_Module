#include <iostream>
#include <string>
#include "Harl.hpp"

void	(Harl::*(Harl::loggers)[Harl::nLoggers])(void) =
{
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

std::string	(Harl::loggernames)[Harl::nLoggers] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

Harl::Harl(void): _level(0)
{
}

Harl::Harl(const Harl &orig): _level(orig._level)
{
}

Harl::~Harl(void)
{
}

Harl	&Harl::operator=(const Harl &orig)
{
	_level = orig._level;
	return (*this);
}

Harl::Harl(const std::string &level)
{
	setComplaintLevel(level);
}

void	Harl::complain(std::string level)
{
	int	idx;

	idx = getLevelIndex(level);
	if (idx >= _level)
	{
		std::cout << "[ " << loggernames[idx] << " ]" << std::endl;
		(this->*loggers[idx])();
	}
	else if (idx < 0)
		std::cout << "Unimplemented log level." << std::endl;
}

void	Harl::setComplaintLevel(const std::string &level)
{
	_level = getLevelIndex(level);
}

int	Harl::getLevelIndex(const std::string &level) const
{
	for (int i = 0; i < nLoggers; i++)
	{
		if (loggernames[i] == level)
			return (i);
	}
	return (-1);
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
