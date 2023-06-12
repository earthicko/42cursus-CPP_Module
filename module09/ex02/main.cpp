#include "PmergeMe.hpp"
#include "debugCout.hpp"
#include "isSame.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &cont)
{
	for (size_t i = 0; i < cont.size(); i++)
	{
		os << cont[i];
		if (i != cont.size() - 1)
			os << ", ";
	}
	return (os);
}

std::ostream &operator<<(std::ostream &os, const std::list<int> &cont)
{
	std::list<int>::const_iterator before_end = cont.end();
	before_end--;
	for (std::list<int>::const_iterator it = cont.begin(); it != cont.end(); it++)
	{
		os << *it;
		if (it != before_end)
			os << ", ";
	}
	return (os);
}

void parseInputValues(char **argv, std::vector<int> &inputValues)
{
	argv++;
	while (*argv)
	{
		std::stringstream buf;
		int val;

		buf.str(*argv);
		buf >> val;
		if (buf.fail())
		{
			std::stringstream whatbuf;

			whatbuf << *argv << " is not a integer.";
			throw(std::runtime_error(whatbuf.str()));
		}
		if (val <= 0)
		{
			std::stringstream whatbuf;

			whatbuf << "non-positive number " << val << " found.";
			throw(std::runtime_error(whatbuf.str()));
		}
		inputValues.push_back(val);
		argv++;
	}
}

template <typename _Container>
void assertCompleteSort(const _Container &sorted, const std::vector<int> &reference)
{
	DEBUGCOUT(__func__ << ": Compare ");
	size_t i = 0;
	for (typename _Container::const_iterator it = sorted.begin(); it != sorted.end(); it++)
	{
		DEBUGCOUT(*it << " ");
		if (*it != reference[i])
		{
			std::stringstream buf;
			buf << "Container is not sorted (" << *it << " != " << reference[i] << ")";
			throw(std::logic_error(buf.str()));
		}
		i++;
	}
}

template <typename _Container>
int testPmergeMe(const std::vector<int> &inputValues, const std::vector<int> &sortedValues)
{
	clock_t time_start;
	clock_t time_done;
	time_start = clock();

	_Container buffer(inputValues.begin(), inputValues.end());
	fordJohnsonSort(buffer);
	DEBUGCOUT(buffer);
	assertCompleteSort(buffer, sortedValues);
	time_done = clock();
	return (((time_done - time_start) * 1000000) / CLOCKS_PER_SEC);
}

int main(int argc, char **argv)
{
	std::vector<int> inputValues;
	std::vector<int> sortedValues;
	int vectorDuration;
	int listDuration;

	if (argc < 2)
		return (1);
	try
	{
		parseInputValues(argv, inputValues);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	sortedValues = inputValues;
	std::sort(sortedValues.begin(), sortedValues.end());
	std::cout << "Before: " << inputValues << std::endl;
	std::cout << "After : " << sortedValues << std::endl;
	vectorDuration = testPmergeMe<std::vector<int> >(inputValues, sortedValues);
	listDuration = testPmergeMe<std::list<int> >(inputValues, sortedValues);
	std::cout << "std::vector: Took " << vectorDuration << "us to process " << argc - 1 << " items" << std::endl;
	std::cout << "std::list  : Took " << listDuration << "us to process " << argc - 1 << " items" << std::endl;
	return (0);
}
