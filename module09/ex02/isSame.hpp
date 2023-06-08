#ifndef ISSAME_HPP
#define ISSAME_HPP

template <typename T, typename U>
struct isSame
{
	static const bool value = false;
};

template <typename T>
struct isSame<T, T>
{
	static const bool value = true;
};

#endif
