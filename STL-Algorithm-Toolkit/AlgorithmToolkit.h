#pragma once
#include <iostream>

template <typename Iterator>
void PrintRange(Iterator first, Iterator last)
{
    for (auto it = first; it != last; it++)
    {
		std::cout << *it << "\n";
    }
}
