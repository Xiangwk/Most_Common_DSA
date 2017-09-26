#pragma once

#include <vector>

void bubbleSort(std::vector<int> &v, size_t beg, size_t end)
{
	bool sorted = false;
	while (!sorted)
	{
		//如果在这一趟遍历中没有发生元素的交换，那么证明数组已然有序，可以终止程序
		sorted = true;
		for (size_t i = beg + 1; i < end; ++i)
		{
			if (v[i] < v[i - 1])
			{
				using std::swap;
				swap(v[i - 1], v[i]);
				sorted = false;
			}
		}
		//数组无序部分可以缩短一个长度，因为一趟冒泡后最大元素已就位
		--end;
	}
}