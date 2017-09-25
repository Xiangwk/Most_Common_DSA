#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#define OPTIMIZE__

#include "QuickSort.h"

int main()
{
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<int> u(0, 99);

	std::vector<int> v(30);
	for (size_t i = 0; i < v.size(); ++i)
		v[i] = u(e);

	for (const auto &i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	quickSort(v, 0, v.size());

	for (const auto &i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}