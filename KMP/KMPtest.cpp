#include <iostream>
#include <string>

#define KMP__
//#define KMP_OPTIMIZE

#include "StringMatch.h"

int main()
{
	const char *pattern = "abc";
	const char *str = "aidjfiaesjijabc";

	std::cout << match(pattern, str) << std::endl;

	return 0;
}