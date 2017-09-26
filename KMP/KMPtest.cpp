#include <iostream>
#include <string>

//#define KMP__
//#define KMP_OPTIMIZE

#include "StringMatch.h"

int main()
{
	const char *pattern = "bc";
	const char *str = "absbsbsandfbcadf";

	std::cout << match(pattern, str) << std::endl;

	return 0;
}