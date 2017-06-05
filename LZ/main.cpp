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

	std::vector<LZ::LZref> references;

	for (int i = 0; i < 10000; i++)
	{
		int a = 25;
		a = a * a;
		a = a / a;
	}

	std::cout << "Warm up complete\n";

	clock_t c = clock();

	for (int i = 0; i < 10000; ++i)
	{
		LZ::LZobject* object = new LZ::LZobject;
		LZ::LZref r = vm.Allocate(object);
		references.push_back(r);
	}

	clock_t c2 = clock();

	unsigned long long timetaken = c2 - c;

	std::cout << timetaken; std::cout << "\n";

	clock_t c3 = clock();

	for (int i = 0; i < references.size(); ++i)
	{
		vm.Deallocate(references.at(i));
	}

	clock_t c4 = clock();

	unsigned long long timetaken2 = c4 - c3;

	std::cout << timetaken2; std::cout << "\n";

	std::string xx;
	std::cin >> xx;

	return 0;
}
