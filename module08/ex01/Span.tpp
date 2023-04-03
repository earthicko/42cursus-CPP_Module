#include "Span.hpp"

template <class InputIterator>
void	Span::insert(InputIterator first, InputIterator last)
{
	t_uint	inputSize;

	inputSize = last - first;
	if (inputSize + _vector.size() > _size)
		throw (Span::SpanFullException());
	for (InputIterator iter = first; iter != last; iter++)
		addNumber(*iter);
}
