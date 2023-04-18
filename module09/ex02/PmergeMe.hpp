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

template <>
class	PmergeMe<std::vector<int> >
{
private:
	static const int	_threshold = 5;
	std::vector<int>	_data;

	void	insertionSort(const int begin, const int end)
	{
		int	keyIdx;
		int	keyVal;
		int	insertionIdx;

		keyIdx = begin + 1;
		while (keyIdx < end)
		{
			keyVal = _data[keyIdx];
			insertionIdx = std::upper_bound(&_data[begin], &_data[keyIdx], keyVal) - &_data[0];
			if (keyIdx != insertionIdx)
			{
				for (int i = keyIdx - 1; i >= insertionIdx; i--)
					_data[i + 1] = _data[i];
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
};

template <>
class	PmergeMe<std::list<int> >
{
private:
	static const int					_threshold = 5;
	typedef std::list<int>::iterator	iterator;
	std::list<int>						_data;

	iterator	getIter(int idx)
	{
		iterator	iter;

		iter = _data.begin();
		std::advance(iter, idx);
		return (iter);
	}

	void	insertionSort(const int begin, const int end)
	{
		int			keyVal;
		iterator	key;
		iterator	insertionPoint;
		iterator	insertedPoint;
		iterator	beginIter;
		iterator	endIter;
		iterator	nextKey;

		beginIter = getIter(begin);
		key = beginIter;
		endIter = beginIter;
		std::advance(key, 1);
		std::advance(endIter, end - begin);
		while (key != endIter)
		{
			nextKey = key;
			nextKey++;
			keyVal = *key;
			insertionPoint = std::upper_bound(beginIter, key, keyVal);
			if (key != insertionPoint)
			{
				_data.erase(key);
				insertedPoint = _data.insert(insertionPoint, keyVal);
				if (insertionPoint == beginIter)
					beginIter = insertedPoint;
			}
			key = nextKey;
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
		merge(getIter(begin), getIter(middle), getIter(end));
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
		mergeInsertionSort(0, _data.size());
	}
};

#endif
