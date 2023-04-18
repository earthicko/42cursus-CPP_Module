#include "PmergeMe.hpp"
#include "isSame.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

template <typename _Container>
void	testPmergeMe(int argc, char **argv)
{
	PmergeMe<_Container>	pmergeMe;
	clock_t					time_start;
	clock_t					time_done;
	int						duration;

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
			std::cerr << "Error: non-positive number " << val << std::endl;
			return ;
		}
		pmergeMe.append(val);
		argv++;
	}
	std::cout << "Before: " << pmergeMe << "\n";
	pmergeMe.sort();
	std::cout << "After : " << pmergeMe << "\n";
	time_done = clock();
	duration = ((time_done - time_start) * 1000000) / CLOCKS_PER_SEC;
	if (isSame<_Container, std::vector<int> >::value)
		std::cout << "std::vector: ";
	if (isSame<_Container, std::list<int> >::value)
		std::cout << "std::list  : ";
	std::cout << "Took " << duration << "us to process " << argc - 1 << " items" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	testPmergeMe<std::vector<int> >(argc, argv);
	testPmergeMe<std::list<int> >(argc, argv);
	return (0);
}
