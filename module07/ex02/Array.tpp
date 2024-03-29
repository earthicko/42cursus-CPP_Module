#include "Array.hpp"
#include <stdexcept>
#include <sstream>

template <typename T>
Array<T>::Array(void)
{
	_n = 0;
	array = new T[_n];
}

template <typename T>
Array<T>::Array(const Array<T> &orig)
{
	if (this == &orig)
		return ;
	_n = orig._n;
	array = new T[_n];
	for (t_uint i = 0; i < _n; i++)
		array[i] = orig.array[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] array;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &orig)
{
	if (this == &orig)
		return (*this);
	delete[] array;
	_n = orig._n;
	array = new T[_n];
	for (t_uint i = 0; i < _n; i++)
		array[i] = orig.array[i];
}

template <typename T>
Array<T>::Array(t_uint n)
{
	_n = n;
	array = new T[_n];
	for (t_uint i = 0; i < _n; i++)
		array[i] = T();
}

template <typename T>
T	&Array<T>::operator[](t_uint idx)
{
	if (_n <= idx)
	{
		std::ostringstream	buf;
		std::string			what;

		buf << idx;
		what = "Index " + buf.str() + " is out of bound.";
		throw (std::runtime_error(what));
	}
	return (array[idx]);
}

template <typename T>
const T	&Array<T>::operator[](t_uint idx) const
{
	if (_n <= idx)
	{
		std::ostringstream	buf;
		std::string			what;

		buf << idx;
		what = "Index " + buf.str() + " is out of bound.";
		throw (std::runtime_error(what));
	}
	return (array[idx]);
}

template <typename T>
t_uint	Array<T>::size(void) const
{
	return (_n);
}
