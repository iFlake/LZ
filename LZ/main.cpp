/*#include <vector>*/
#include <iostream>
#include <sstream>
#include <time.h>/*
#include <iomanip>
#include <locale>*/

#include "lzvm.h"

int main()
{
	/*std::vector<char> test;

	std::ostringstream s;
	s << test.max_size();
	
	std::cout << s.str();*/

	LZ::LZvm vm;

	std::vector<int> references;

	clock_t c = clock();

	for (int i = 0; i < 1000; ++i)
	{
		LZ::LZobject* object = new LZ::LZobject;
		//vm.Allocate(object);
	}

	clock_t c2 = clock();

	unsigned long long timetaken = c2 - c;

	std::cout << timetaken;

	std::string xx;
	std::cin >> xx;

	return 0;
}
