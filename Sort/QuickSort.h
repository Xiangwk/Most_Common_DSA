#pragma once

#include <vector>

size_t partition(std::vector<int> &v, size_t lo, size_t hi);

void quickSort(std::vector<int> &v, size_t beg, size_t end)
{
	if (end - beg < 2) return;

	size_t p = partition(v, beg, end - 1);

	quickSort(v, beg, p);
	quickSort(v, p + 1, end);
}

//这是基础版本的快速划分算法，该版本存在一个问题：当数组所有元素均重复的时候，时间复杂度会急剧上升到最坏情况O(n^2)
//另一个版本的算法可以解决这个问题，但是每次划分可能会产生更多次的赋值操作，但是总体时间复杂度不受影响，而且在退化情况
//下，时间复杂度会达到最好的O(logn);    注：第二个版本会加剧快排的不稳定性！
#ifdef EDITION_A

size_t partition(std::vector<int> &v, size_t lo, size_t hi)
{
	using std::swap;
	swap(v[lo], v[lo + rand() % (hi - lo + 1)]);
	int pivot = v[lo];
	while (lo < hi)
	{
		while (lo < hi && pivot <= v[hi]) --hi;
		v[lo] = v[hi];
		while (lo < hi && v[lo] <= pivot) ++lo;
		v[hi] = v[lo];
	}
	v[lo] = pivot;
	return lo;
}

#else

size_t partition(std::vector<int> &v, size_t lo, size_t hi)
{
	using std::swap;
	swap(v[lo], v[lo + rand() % (hi - lo + 1)]);
	int pivot = v[lo];

	while (lo < hi)
	{
		while (lo < hi)
		{
			if (pivot < v[hi]) --hi;
			else
			{
				v[lo++] = v[hi];
				break;
			}
		}
		while (lo < hi)
		{
			if (v[lo] < pivot) ++lo;
			else
			{
				v[hi--] = v[lo];
				break;
			}
		}
	}
	v[lo] = pivot;
	return lo;
}

#endif