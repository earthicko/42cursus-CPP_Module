#include "Span.hpp"
#include <limits>

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

unsigned int	Span::shortestSpan(void) const
{
	long long	minimum;
	long long	candidate;

	if (_vector.size() <= 1)
		throw (Span::NotEnoughElementsException());
	minimum = std::numeric_limits<unsigned int>::max();
	for (t_uint i = 1; i < _vector.size(); i++)
	{
		candidate = (long long)_vector[i] - (long long)_vector[i - 1];
		if (candidate < minimum)
			minimum = candidate;
	}
	return (minimum);
}

unsigned int	Span::longestSpan(void) const
{
	long long	front;
	long long	back;

	if (sizeof(long long) != sizeof(int) * 2)
		throw (std::runtime_error("size of (long long) is not the double of size of (int)."));
	if (_vector.size() <= 1)
		throw (Span::NotEnoughElementsException());
	front = _vector.front();
	back = _vector.back();
	return (back - front);
}

Span::SpanFullException::SpanFullException(void):
	std::runtime_error("Span is full.")
{
}

Span::NotEnoughElementsException::NotEnoughElementsException(void):
	std::runtime_error("Not enough elements to determine span.")
{
}
