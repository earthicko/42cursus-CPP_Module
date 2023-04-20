#include "PmergeMe.hpp"
#include "isSame.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

template <typename _Container>
int	testPmergeMe(char **argv)
{
	PmergeMe<_Container>	pmergeMe;
	clock_t					time_start;
	clock_t					time_done;

	time_start = clock();
	argv++;
	while (*argv)
	{
		std::stringstream	buf;
		int					val;

		buf.str(*argv);
		buf >> val;
		if (val <= 0)
		{
			std::stringstream	whatbuf;

			whatbuf << "non-positive number " << val << " found.";
			throw (std::runtime_error(whatbuf.str()));
		}
		pmergeMe.append(val);
		argv++;
	}
	std::cout << "Before: " << pmergeMe << "\n";
	pmergeMe.sort();
	std::cout << "After : " << pmergeMe << "\n";
	time_done = clock();
	return (((time_done - time_start) * 1000000) / CLOCKS_PER_SEC);
}

int	main(int argc, char **argv)
{
	int	vectorDuration;
	int	listDuration;

	if (argc < 2)
		return (1);
	try
	{
		vectorDuration = testPmergeMe<std::vector<int> >(argv);
		listDuration = testPmergeMe<std::list<int> >(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	std::cout << "std::vector: " << "Took " << vectorDuration << "us to process " << argc - 1 << " items" << std::endl;
	std::cout << "std::list  : " << "Took " << listDuration << "us to process " << argc - 1 << " items" << std::endl;
	return (0);
}
