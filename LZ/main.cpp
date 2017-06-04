#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale>

int main()
{
	std::vector<char> test;

	std::ostringstream s;
	s << test.max_size();
	
	std::cout << s.str();

	std::string xx;
	std::cin >> xx;

	return 0;
}
