#include <cstddef>
#include <stdexcept>

const size_t cacheSize = 64;

ssize_t getJacobsthalDiff(ssize_t idx)
{
	static ssize_t cache[cacheSize];

	if (idx >= cacheSize)
		throw(std::runtime_error(""));
	if (cache[idx] == 0)
	{
		if (idx == 0)
			cache[idx] = 2;
		else
			cache[idx] = (1 << (idx + 1)) - getJacobsthalDiff(idx - 1);
	}
	return (cache[idx]);
}
