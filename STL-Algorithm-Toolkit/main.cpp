#include <iostream>
#include <vector>
#include <list>

#include "AlgorithmToolkit.h"

void TestPrintRange()
{
	std::cout << "=== Test Iterators ===" << std::endl;

	std::vector<int> numbers{ 10, 20, 30, 40 };
	PrintRange(numbers.begin(), numbers.end());

	std::list<int> numbers2{ 10, 20, 30, 40 };
	PrintRange(numbers2.begin(), numbers2.end());

	std::vector<std::string> string{ "apple", "banana", "cat", "dog" };
	PrintRange(string.begin(), string.end());

	std::cout << "------------------------------" << std::endl;
}
int main()
{
	TestPrintRange();

	return 0;
}