#include <iostream>
#include <string>

#define KMP__
#define KMP_OPTIMIZE

#include "StringMatch.h"

int main()
{
	std::string pattern = "bc";
	std::string str = "absbsbsandfbcadf";

	std::cout << match(pattern, str) << std::endl;

	return 0;
}