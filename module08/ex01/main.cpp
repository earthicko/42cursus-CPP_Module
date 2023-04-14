#include "Span.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

void	getShortestSpan(const Span &span)
{
	try
	{
		unsigned int	shortestSpan;

		shortestSpan = span.shortestSpan();
		std::cout << "Shortest span: " << shortestSpan << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void	getLongestSpan(const Span &span)
{
	try
	{
		unsigned int	longestSpan;

		longestSpan = span.longestSpan();
		std::cout << "longest span: " << longestSpan << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void	testExceptions(void)
{
	Span	span(1);

	std::cout << __func__ << "() ===========================================\n";
	getShortestSpan(span);
	getLongestSpan(span);
	span.addNumber(3);
	getShortestSpan(span);
	getLongestSpan(span);
	try
	{
		span.addNumber(7);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void	testModerateSpansize(void)
{
	Span		span(10);
	const int	intArr[] = {
		std::numeric_limits<int>::max(),
		std::numeric_limits<int>::min(),
		4,
		8
	};

	std::cout << __func__ << "() ===========================================\n";
	for (size_t i = 0; i < sizeof(intArr) / sizeof(int); i++)
		span.addNumber(intArr[i]);
	getShortestSpan(span);
	getLongestSpan(span);
}

void	testBigSpansize(void)
{
	const int			spansize = 100000;
	std::vector<int>	v;
	Span				span(spansize);

	std::cout << __func__ << "() ===========================================\n";
	std::srand(std::time(0));
	for (int i = 0; i < spansize; i++)
	{
		int	randInt;
		int	randSign;

		randInt = std::rand();
		randSign = std::rand() % 2;
		if (randSign)
			randInt *= -1;
		v.push_back(randInt);
	}
	span.insert(v.begin(), v.end());
	getShortestSpan(span);
	getLongestSpan(span);
}

int	main(void)
{
	testExceptions();
	testModerateSpansize();
	testBigSpansize();
	return (0);
}
