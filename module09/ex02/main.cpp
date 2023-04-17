#include "PmergeMe.hpp"
#include "isSame.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

typedef std::chrono::steady_clock::time_point	time_point;
typedef std::chrono::microseconds				t_us;

template <typename _Container>
void	testPmergeMe(int argc, char **argv)
{
	PmergeMe<_Container>	pmergeMe;
	time_point				time_start;
	time_point				time_done;
	t_us					duration;

	time_start = std::chrono::high_resolution_clock::now();
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
	time_done = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<t_us>(time_done - time_start);
	if (isSame<_Container, std::vector<int> >::value)
		std::cout << "std::vector: ";
	if (isSame<_Container, std::list<int> >::value)
		std::cout << "std::list  : ";
	std::cout << "Took " << duration.count() << "us to process " << argc - 1 << " items" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	testPmergeMe<std::vector<int> >(argc, argv);
	testPmergeMe<std::list<int> >(argc, argv);
	return (0);
}
