#pragma once

#include <vector>

size_t selectMax(const std::vector<int> &v, size_t beg, size_t end)
{
	int maxVal = v[beg];
	size_t m = beg;

	for (size_t i = beg + 1; i != end; ++i)
	{
		if (maxVal < v[i])
		{
			maxVal = v[i];
			m = i;
		}
	}

	return m;
}

void selectionSort(std::vector<int> &v, size_t beg, size_t end)
{
	for (size_t i = beg; i != end; ++i)
	{
		size_t m = selectMax(v, beg, end - i);
		using std::swap;
		swap(v[m], v[end - i - 1]);
	}
}