#pragma once

#include <vector>

void insertionSort(std::vector<int> &v, int beg, int end)
{
	for (int i = beg + 1; i != end; ++i)
	{
		//先存储待插入的元素，因为在搜索位置的过程中，数组元素需要移动出插入的位置
		//在移动过程中，这个值会被覆盖掉
		int t = v[i];
		int j = i - 1;
		for (; j >= 0 && t < v[j]; --j)
			v[j + 1] = v[j];
		v[j + 1] = t;
	}
}