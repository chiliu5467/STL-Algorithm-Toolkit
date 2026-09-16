#pragma once
#include <iostream>

template <typename Iterator>
void PrintRange(Iterator first, Iterator last)
{
    for (auto it = first; it != last; ++it)
    {
		std::cout << *it << "\n";
    }
}

template <typename Iterator, typename T>
Iterator FindValue(Iterator first, Iterator last, const T& value)
{
    for (auto it = first; it != last; ++it)
    {
        if (*it == value)
        {
            return it;
        }
    }

    return last;
}

template <typename Iterator, typename Predicate>
Iterator FindIf(
    Iterator first,
    Iterator last,
    Predicate predicate)
{
    while (first != last)
    {
        if (predicate(*first))
        {
            return first;
        }

        ++first;
    }

    return last;
}
