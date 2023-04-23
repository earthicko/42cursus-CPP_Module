#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <algorithm>
# include <stdexcept>
# include <iostream>

template <typename T>
class	PmergeMe;

std::ostream	&operator<<(std::ostream &os, PmergeMe<std::vector<int> > lp);
std::ostream	&operator<<(std::ostream &os, PmergeMe<std::list<int> > lp);

template <typename T>
bool	isContainerSorted(T &container)
{
	typename T::iterator	first;
	typename T::iterator	second;

	if (container.size() <= 1)
		return (true);
	first = container.begin();
	second = container.begin();
	second++;
	while (second != container.end())
	{
		if (*first > *second)
			return (false);
		first++;
		second++;
	}
	return (true);
}

template <>
class	PmergeMe<std::vector<int> >
{
private:
	static const int	_threshold = 5;
	std::vector<int>	_data;

	void	insertionSort(const int begin, const int end)
	{
		int	keyIdx;

		keyIdx = begin + 1;
		while (keyIdx < end)
		{
			int	keyVal;
			int	insertionIdx;

			keyVal = _data[keyIdx];
			insertionIdx = std::upper_bound(&_data[begin], &_data[keyIdx], keyVal) - &_data[0];
			if (keyIdx != insertionIdx)
			{
				for (int i = keyIdx; i > insertionIdx; i--)
					_data[i] = _data[i - 1];
				_data[insertionIdx] = keyVal;
			}
			keyIdx++;
		}
	}

	void	merge(int begin, int middle, int end)
	{
		std::vector<int>	merged;
		int					lidx;
		int					lend;
		int					ridx;
		int					rend;
		int					mergedidx;

		lidx = begin;
		lend = middle;
		ridx = middle;
		rend = end;
		while (lidx != lend && ridx != rend)
		{
			if (_data[lidx] < _data[ridx])
			{
				merged.push_back(_data[lidx]);
				lidx++;
			}
			else
			{
				merged.push_back(_data[ridx]);
				ridx++;
			}
		}
		merged.insert(merged.end(), &_data[lidx], &_data[lend]);
		merged.insert(merged.end(), &_data[ridx], &_data[rend]);
		mergedidx = 0;
		while (begin != end)
		{
			_data[begin] = merged[mergedidx];
			begin++;
			mergedidx++;
		}
	}

	void	mergeInsertionSort(const int begin, const int end)
	{
		const int	middle = begin + (end - begin) / 2;

		if (end - begin <= _threshold)
		{
			insertionSort(begin, end);
			return ;
		}
		mergeInsertionSort(begin, middle);
		mergeInsertionSort(middle, end);
		merge(begin, middle, end);
	}

public:
				PmergeMe(void): _data() {}
				PmergeMe(const PmergeMe &orig): _data(orig._data) {}
				~PmergeMe(void) {}
	PmergeMe	&operator=(const PmergeMe &orig)
	{
		_data = orig._data;
		return (*this);
	}

	std::vector<int>	&getData(void)
	{
		return (_data);
	}

	void	append(int newval)
	{
		_data.push_back(newval);
	}

	void	sort(void)
	{
		mergeInsertionSort(0, _data.size());
	}

	bool	isSorted(void)
	{
		return (isContainerSorted(_data));
	}
};

template <>
class	PmergeMe<std::list<int> >
{
private:
	static const int					_threshold = 5;
	typedef std::list<int>::iterator	iterator;
	std::list<int>						_data;

	void	insertionSort(iterator begin, iterator end)
	{
		iterator	key;

		key = begin;
		key++;
		while (key != end)
		{
			iterator	insertionPoint;
			int			keyVal;

			keyVal = *key;
			insertionPoint = std::upper_bound(begin, key, keyVal);
			if (key != insertionPoint)
			{
				for (iterator after = key; after != insertionPoint; after--)
				{
					iterator	before;

					before = after;
					before--;
					*after = *before;
				}
				*insertionPoint = keyVal;
			}
			key++;
		}
	}

	void	merge(iterator begin, iterator middle, iterator end)
	{
		std::list<int>	merged;
		iterator		lbegin;
		iterator		lend;
		iterator		rbegin;
		iterator		rend;
		iterator		mergedit;

		lbegin = begin;
		lend = middle;
		rbegin = middle;
		rend = end;
		while (lbegin != lend && rbegin != rend)
		{
			if (*lbegin < *rbegin)
			{
				merged.push_back(*lbegin);
				lbegin++;
			}
			else
			{
				merged.push_back(*rbegin);
				rbegin++;
			}
		}
		merged.insert(merged.end(), lbegin, lend);
		merged.insert(merged.end(), rbegin, rend);
		mergedit = merged.begin();
		while (begin != end)
		{
			*begin = *mergedit;
			begin++;
			mergedit++;
		}
	}

	void	mergeInsertionSort(iterator begin, iterator end)
	{
		iterator	middle;
		int			d;

		d = std::distance(begin, end);
		if (d <= _threshold)
		{
			insertionSort(begin, end);
			return ;
		}
		middle = begin;
		std::advance(middle, d / 2);
		mergeInsertionSort(begin, middle);
		mergeInsertionSort(middle, end);
		merge(begin, middle, end);
	}

public:
				PmergeMe(void): _data() {}
				PmergeMe(const PmergeMe &orig): _data(orig._data) {}
				~PmergeMe(void) {}
	PmergeMe	&operator=(const PmergeMe &orig)
	{
		_data = orig._data;
		return (*this);
	}

	std::list<int>	&getData(void)
	{
		return (_data);
	}

	void	append(int newval)
	{
		_data.push_back(newval);
	}

	void	sort(void)
	{
		mergeInsertionSort(_data.begin(), _data.end());
	}

	bool	isSorted(void)
	{
		return (isContainerSorted(_data));
	}
};

#endif
