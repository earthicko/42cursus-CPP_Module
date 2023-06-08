#include "PmergeMe.hpp"
#include "isSame.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

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
int testPmergeMe(const std::vector<int> &inputValues,
				 PmergeMe<_Container> &pmergeme)
{
	clock_t time_start;
	clock_t time_done;

	time_start = clock();
	for (std::vector<int>::size_type i = 0; i < inputValues.size(); i++)
		pmergeme.append(inputValues[i]);
	pmergeme.sort();
	time_done = clock();
	if (!pmergeme.isSorted())
		throw(std::logic_error("Container is not sorted."));
	return (((time_done - time_start) * 1000000) / CLOCKS_PER_SEC);
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &v)
{
	for (std::vector<int>::size_type i = 0; i < v.size(); i++)
	{
		os << v[i];
		if (i != v.size() - 1)
			os << " ";
	}
	return (os);
}

int main(int argc, char **argv)
{
	std::vector<int> inputValues;
	PmergeMe<std::vector<int> > vectorMergeMe;
	PmergeMe<std::list<int> > listMergeMe;
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
	vectorDuration = testPmergeMe(inputValues, vectorMergeMe);
	listDuration = testPmergeMe(inputValues, listMergeMe);
	std::cout << "Before: " << inputValues << std::endl;
	std::cout << "After : " << vectorMergeMe << std::endl;
	std::cout << "std::vector: Took " << vectorDuration << "us to process "
			  << argc - 1 << " items" << std::endl;
	std::cout << "std::list  : Took " << listDuration << "us to process "
			  << argc - 1 << " items" << std::endl;
	return (0);
}
