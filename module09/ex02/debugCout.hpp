#ifndef DEBUGCOUT_HPP
#define DEBUGCOUT_HPP

#include <iostream>

#define DEBUG

#ifdef DEBUG
#define DEBUGCOUT(message)                                                                                             \
	do                                                                                                                 \
	{                                                                                                                  \
		std::cout << message;                                                                                          \
	} while (0)
#else
#define DEBUGCOUT(message)                                                                                             \
	do                                                                                                                 \
	{                                                                                                                  \
	} while (0)
#endif

#endif
