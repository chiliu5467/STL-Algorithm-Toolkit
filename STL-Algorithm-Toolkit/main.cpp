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

	std::vector<std::string> words{ "apple", "banana", "cat", "dog" };
	PrintRange(words.begin(), words.end());

	std::cout << "------------------------------" << std::endl;
}

void TestFindValue()
{
	std::cout << "=== Test Find Value ===" << std::endl;
	std::vector<int> numbers{ 10, 20, 30, 40 };
	auto it = FindValue(numbers.begin(), numbers.end(), 30);
	if (it != numbers.end())
	{
		std::cout << "Found value: " << *it << std::endl;
	}
	else
	{
		std::cout << "Value not found." << std::endl;
	}

	std::list<int> listNumbers{ 10, 20, 30, 40 };
	auto it1 = FindValue(listNumbers.begin(), listNumbers.end(), 50);
	if (it1 != listNumbers.end())
	{
		std::cout << "Found value: " << *it1 << std::endl;
	}
	else
	{
		std::cout << "Value not found." << std::endl;
	}

	std::list<std::string> words{ "apple", "banana", "cat", "dog" };
	auto it2 = FindValue(words.begin(), words.end(), std::string("cat"));
	if (it2 != words.end())
	{
		std::cout << "Found value: " << *it2 << std::endl;
	}
	else
	{
		std::cout << "Value not found." << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
}

int main()
{
	TestPrintRange();
	TestFindValue();

	return 0;
}