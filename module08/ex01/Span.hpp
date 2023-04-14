#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

typedef unsigned int	t_uint;

class	Span
{
public:
						Span(const Span &orig);
						~Span(void);
	Span				&operator=(const Span &orig);

						Span(t_uint n);
	class				SpanFullException: public std::runtime_error
	{
	public:
		SpanFullException(void);
	};
	class				NotEnoughElementsException: public std::runtime_error
	{
	public:
		NotEnoughElementsException(void);
	};
	void				addNumber(int number);
	unsigned int		shortestSpan(void) const;
	unsigned int		longestSpan(void) const;
	template <class InputIterator>
	void				insert(InputIterator first, InputIterator last)
	{
		t_uint	inputSize;

		inputSize = last - first;
		if (inputSize + _vector.size() > _size)
			throw (Span::SpanFullException());
		for (InputIterator iter = first; iter != last; iter++)
			addNumber(*iter);
	}

private:
						Span(void);
	void				clone(const Span &orig);

	std::vector<int>	_vector;
	t_uint				_size;
};

#endif
