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

	void				addNumber(int number);
	template <class InputIterator>
	void				insert(InputIterator first, InputIterator last);
	int					shortestSpan(void) const;
	int					longestSpan(void) const;

	class				SpanFullException;
	class				NotEnoughElementsException;

private:
						Span(void);
	void				clone(const Span &orig);

	std::vector<int>	_vector;
	t_uint				_size;
};

class	Span::SpanFullException: public std::runtime_error
{
public:
	SpanFullException(void);
};

class	Span::NotEnoughElementsException: public std::runtime_error
{
public:
	NotEnoughElementsException(void);
};

# include "Span.tpp"

#endif
