#include "debugCout.hpp"

#ifdef DEBUG

#include <sstream>

std::ostream &operator<<(std::ostream &os, std::list<GroupIterator> &lgi)
{
	for (std::list<GroupIterator>::iterator it = lgi.begin(); it != lgi.end(); it++)
		os << (*it);
	return (os);
}

std::string pendVectorToString(std::vector<std::list<GroupIterator>::iterator> &pend, std::list<GroupIterator> &s)
{
	std::stringstream buf;
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (pend[i] == s.end())
			buf << "(before end)";
		else
			buf << "(before " << *(pend[i]) << ")";
	}
	return (buf.str());
}

std::string pendToString(std::list<GroupIterator>::iterator &pend, std::list<GroupIterator> &s)
{
	std::stringstream buf;
	if (pend == s.end())
		buf << "(before end)";
	else
		buf << "(before " << *pend << ")";
	return (buf.str());
}

std::ostream &operator<<(std::ostream &os, std::list<GroupPointer> &lgi)
{
	for (std::list<GroupPointer>::iterator it = lgi.begin(); it != lgi.end(); it++)
		os << (*it);
	return (os);
}

std::string pendVectorToString(std::vector<std::list<GroupPointer>::iterator> &pend, std::list<GroupPointer> &s)
{
	std::stringstream buf;
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (pend[i] == s.end())
			buf << "(before end)";
		else
			buf << "(before " << *(pend[i]) << ")";
	}
	return (buf.str());
}

#endif
