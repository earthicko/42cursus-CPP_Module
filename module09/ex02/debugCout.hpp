#ifndef DEBUGCOUT_HPP
#define DEBUGCOUT_HPP

#include <iostream>

// #define DEBUG

#ifdef DEBUG
#define DEBUGCOUTLN(message)                                                                                           \
	do                                                                                                                 \
	{                                                                                                                  \
		std::cout << message << std::endl;                                                                             \
	} while (0)
#define DEBUGCOUT(message)                                                                                             \
	do                                                                                                                 \
	{                                                                                                                  \
		std::cout << message;                                                                                          \
	} while (0)
#else
#define DEBUGCOUTLN(message)                                                                                           \
	do                                                                                                                 \
	{                                                                                                                  \
	} while (0)
#define DEBUGCOUT(message)                                                                                             \
	do                                                                                                                 \
	{                                                                                                                  \
	} while (0)
#endif

#endif
