#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

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

void TestFindIf()
{
	std::cout << "=== Test Find If ===" << std::endl;
	std::vector<int> numbers{
	1, 3, 7, 8, 11, 12
	};
	auto it = FindIf(numbers.begin(), numbers.end(), 
		[](int value) {return value % 2 == 0;});
	if (it != numbers.end())
	{
		std::cout << "Found even value: " << *it << std::endl;
	}
	else
	{
		std::cout << "Even value not found." << std::endl;
	}

	auto stdIt = std::find_if(
		numbers.begin(),
		numbers.end(),
		[](int value)
		{
			return value % 2 == 0;
		});

	std::cout << "My FindIf: " << *it << '\n';
	std::cout << "std::find_if: " << *stdIt << '\n';

	int threshold = 20;

	std::list<int> values{
		5, 15, 25, 35
	};

	auto it2 = FindIf(values.begin(), values.end(), 
		[threshold](int value) { return value > threshold;});

	if (it2 != values.end())
	{
		std::cout << "Found value greater than " << threshold << ": " << *it2 << std::endl;
	}
	else
	{
		std::cout << "Value greater than " << threshold << " not found." << std::endl;
	}

	std::vector<std::string> words{
	"cat",
	"elephant",
	"dog",
	"giraffe"
	};

	int thresholdLength = 5;
	auto it3 = FindIf(words.begin(), words.end(), 
		[thresholdLength](const std::string& word) {return word.length() > thresholdLength;});
	if (it3 != words.end())
	{
		std::cout << "Found word with length greater than 5: " << *it3 << std::endl;
	}
	else
	{
		std::cout << "Word with length greater than " << thresholdLength <<  " not found." << std::endl;
	}

	std::cout << "------------------------------" << std::endl;
}

void TestCountIf()
{
	std::cout << "=== Test Count If ===" << std::endl;
	std::vector<int> numbers{
		1, 3, 7, 8, 11, 12
	};
	int count = CountIf(numbers.begin(), numbers.end(),
		[](int value) {return value % 2 == 0;});
	int stdCount = std::count_if(numbers.begin(), numbers.end(),
		[](int value) {return value % 2 == 0;});
	std::cout << "Count of even values: " << count << std::endl;
	std::cout << "std::count_if: " << stdCount << std::endl;

	int threshold = 20;
	std::list<int> values{
		5, 15, 25, 35
	};
	int count2 = CountIf(values.begin(), values.end(),
		[threshold](int value) { return value > threshold; });
	std::cout << "Count of values greater than " << threshold << ": " << count2 << std::endl;
	
	std::vector<std::string> words{
		"cat",
		"elephant",
		"dog",
		"giraffe"
	};
	int thresholdLength = 5;
	int count3 = CountIf(words.begin(), words.end(),
		[thresholdLength](const std::string& word) {return word.length() > thresholdLength; });
	std::cout << "Count of words with length greater than " << thresholdLength << ": " << count3 << std::endl;
	std::cout << "------------------------------" << std::endl;
}

void TestEdgeCases()
{
	std::cout << "=== Test Edge Cases ===\n";

	// Empty range
	std::vector<int> empty;
	auto emptyIt = FindValue(empty.begin(), empty.end(), 10);

	if (emptyIt == empty.end())
	{
		std::cout << "Empty range: passed\n";
	}

	// Single element
	std::vector<int> single{ 42 };
	auto singleIt = FindValue(single.begin(), single.end(), 42);

	if (singleIt != single.end())
	{
		std::cout << "Single element: passed\n";
	}

	// No match
	std::vector<int> values{ 1, 3, 5 };
	auto noMatch = FindIf(
		values.begin(),
		values.end(),
		[](int value) { return value % 2 == 0; });

	if (noMatch == values.end())
	{
		std::cout << "No match: passed\n";
	}

	// All match
	auto count = CountIf(
		values.begin(),
		values.end(),
		[](int value) { return value % 2 != 0; });

	if (count == values.size())
	{
		std::cout << "All match: passed\n";
	}
}

int main()
{
	TestPrintRange();
	TestFindValue();
	TestFindIf();
	TestCountIf();
	TestEdgeCases();

	return 0;
}