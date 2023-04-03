#include "Span.hpp"
#include <limits.h>

Span::Span(const Span &orig)
{
	if (this == &orig)
		return ;
	clone(orig);
}

Span::~Span(void)
{
}

Span	&Span::operator=(const Span &orig)
{
	if (this == &orig)
		return (*this);
	clone(orig);
	return (*this);
}

Span::Span(t_uint n)
{
	_size = n;
}

void	Span::addNumber(int number)
{
	std::vector<int>::iterator	bound;

	if (_vector.size() >= _size)
		throw (Span::SpanFullException());
	bound = std::lower_bound(_vector.begin(), _vector.end(), number);
	_vector.insert(bound, number);
}

void	Span::clone(const Span &orig)
{
	_size = orig._size;
	_vector = orig._vector;
}

int	Span::shortestSpan(void)
{
	int	minimum;
	int	candidate;

	if (_vector.size() <= 1)
		throw (Span::NotEnoughElementsException());
	minimum = INT_MAX;
	for (t_uint i = 1; i < _vector.size(); i++)
	{
		candidate = _vector[i] - _vector[i - 1];
		if (candidate < minimum)
			minimum = candidate;
	}
	return (minimum);
}

int	Span::longestSpan(void)
{
	if (_vector.size() <= 1)
		throw (Span::NotEnoughElementsException());
	return (*(_vector.end()) - *(_vector.begin()));
}

Span::SpanFullException::SpanFullException(void):
	std::runtime_error("Span is full.")
{
}

Span::NotEnoughElementsException::NotEnoughElementsException(void):
	std::runtime_error("Not enough elements to determine span.")
{
}
