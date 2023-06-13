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

#ifdef DEBUG

#include "GroupIterator.hpp"
#include "GroupPointer.hpp"

std::ostream &operator<<(std::ostream &os, std::list<GroupIterator> &lgi);
std::string pendVectorToString(std::vector<std::list<GroupIterator>::iterator> &pend, std::list<GroupIterator> &s);
std::string pendToString(std::list<GroupIterator>::iterator &pend, std::list<GroupIterator> &s);
std::ostream &operator<<(std::ostream &os, std::list<GroupPointer> &lgi);
std::string pendVectorToString(std::vector<std::list<GroupPointer>::iterator> &pend, std::list<GroupPointer> &s);

#endif

#endif
