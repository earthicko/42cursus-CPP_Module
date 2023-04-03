#include "Span.hpp"
#include <vector>
#include <iostream>

void	getShortestSpan(const Span &span)
{
	try
	{
		int	shortestSpan;

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
		int	longestSpan;

		longestSpan = span.longestSpan();
		std::cout << "longest span: " << longestSpan << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

int	main(void)
{
	Span				span(10);
	std::vector<int>	twoPowered;
	std::vector<int>	fourPowered;

	for(int i = 4; i > 0; i--)
	{
		twoPowered.push_back((1 << i));
		fourPowered.push_back((1 << (i * 2)));
	}
	span.addNumber(3);
	getShortestSpan(span);
	getLongestSpan(span);
	span.addNumber(7);
	getShortestSpan(span);
	getLongestSpan(span);
	span.addNumber(1);
	getShortestSpan(span);
	getLongestSpan(span);
	span.insert(twoPowered.begin(), twoPowered.end());
	getShortestSpan(span);
	getLongestSpan(span);
	span.addNumber(2);
	getShortestSpan(span);
	getLongestSpan(span);
	try
	{
		span.insert(fourPowered.begin(), fourPowered.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
