#pragma once

#include <vector>

//从ｉ开始下滤直到ｎ
void percolateDown(std::vector<int> &v, size_t i, size_t n)
{
	size_t j = 2 * i + 2;
	while (j < n && (v[i] < v[j - 1] || v[i] < v[j]))
	{
		using std::swap;
		if (v[j] < v[j - 1])
		{
			swap(v[i], v[j - 1]);
			i = j - 1;
		}
		else
		{
			swap(v[i], v[j]);
			i = j;
		}
		j = 2 * i + 2;
	}
	if (j - 1 < n && v[i] < v[j - 1])
	{
		using std::swap;
		swap(v[i], v[j - 1]);
	}
}

//就地建堆
void heapification(std::vector<int> &v)
{
	int sz = v.size();
	int i = sz - 1;
	while (2 * i + 2 > sz - 1 && 2 * i + 1 > sz - 1)
		--i;

	while (i >= 0)
		percolateDown(v, i--, sz);
}

void heapSort(std::vector<int> &v, size_t beg, size_t end)
{
	heapification(v);
	while (end > 1)
	{
		using std::swap;
		swap(v[beg], v[end - 1]);

		percolateDown(v, beg, end - 1);
		--end;
	}
}