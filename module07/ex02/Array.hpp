#ifndef ARRAY_HPP
# define ARRAY_HPP

typedef unsigned int	t_uint;

template <typename T>
class	Array
{
public:
			Array(void);
			Array(const Array &orig);
			~Array(void);
	Array	&operator=(const Array &orig);

			Array(t_uint n);

	T		&operator[](t_uint idx);
	const T	&operator[](t_uint idx) const;
	t_uint	size(void) const;

private:
	T		*array;
	t_uint	_n;
};

# include "Array.tpp"

#endif
