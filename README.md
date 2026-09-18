# STL Algorithm Toolkit

A small C++ learning project that implements simplified STL-style generic algorithms using templates, iterators, and predicates.

The goal of this project is to understand how generic algorithms work across different container types without depending on a specific container implementation.

## Implemented Algorithms

### `PrintRange`

Prints every element in a half-open iterator range:

```cpp
[first, last)
```

```cpp
template <typename Iterator>
void PrintRange(Iterator first, Iterator last);
```

### `FindValue`

Finds the first element equal to a specified value.

```cpp
template <typename Iterator, typename T>
Iterator FindValue(
    Iterator first,
    Iterator last,
    const T& value);
```

If no matching value is found, the function returns `last`.

### `FindIf`

Finds the first element that satisfies a caller-provided predicate.

```cpp
template <typename Iterator, typename Predicate>
Iterator FindIf(
    Iterator first,
    Iterator last,
    Predicate predicate);
```

The traversal logic stays inside the algorithm, while the caller defines what counts as a match.

### `CountIf`

Counts how many elements satisfy a caller-provided predicate.

```cpp
template <typename Iterator, typename Predicate>
std::size_t CountIf(
    Iterator first,
    Iterator last,
    Predicate predicate);
```

Unlike `FindIf`, which can stop when the first matching element is found, `CountIf` must traverse the entire range to calculate the total number of matches.

## Example

```cpp
#include "AlgorithmToolkit.h"

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{ 1, 3, 7, 8, 11, 12 };

    auto it = FindIf(
        values.begin(),
        values.end(),
        [](int value)
        {
            return value % 2 == 0;
        });

    if (it != values.end())
    {
        std::cout << "First even value: " << *it << '\n';
    }

    std::size_t count = CountIf(
        values.begin(),
        values.end(),
        [](int value)
        {
            return value % 2 == 0;
        });

    std::cout << "Even count: " << count << '\n';
}
```

## Generic Iterator-Based Design

The algorithms work with iterator ranges rather than directly depending on a specific container.

For example, the algorithms are tested with:

- `std::vector<int>`
- `std::list<int>`
- `std::vector<std::string>`
- `std::list<std::string>`

The algorithms only require the iterator operations they actually use, such as:

```cpp
*it
++it
it != last
```

They do not require random-access operations such as:

```cpp
it + n
it[n]
```

Because of this, they can also work with containers such as `std::list`, whose iterators do not support random access.

## Predicates

`FindIf` and `CountIf` accept a predicate that defines whether an element matches a condition.

Example:

```cpp
[](int value)
{
    return value > 20;
}
```

Predicates can also capture external values:

```cpp
int threshold = 20;

[threshold](int value)
{
    return value > threshold;
}
```

This separates:

- how the algorithm traverses the range
- what condition defines a match

and makes the same algorithm reusable for many different conditions.

## Comparison with the Standard Library

The custom implementations are compared with standard library algorithms such as:

```cpp
std::find_if
std::count_if
```

This project is not intended to replace the C++ standard library.

Instead, implementing simplified versions manually helps demonstrate how templates, iterator ranges, predicates, and control flow work together behind STL-style generic algorithms.

## Edge Case Testing

The project also includes tests for common edge cases:

- empty ranges
- single-element ranges
- no matching element
- all elements matching

These tests verify that the algorithms correctly handle iterator boundaries and return `last` when no matching element is found.

## Complexity

| Algorithm | Time Complexity | Behavior |
|---|---|---|
| `PrintRange` | O(n) | Visits every element |
| `FindValue` | O(n) worst case | Stops at the first matching value |
| `FindIf` | O(n) worst case | Stops at the first element satisfying the predicate |
| `CountIf` | O(n) | Traverses the full range |

## What I Learned

Through this project, I practiced:

- Function templates
- Generic programming
- Iterator-based algorithms
- Half-open ranges `[first, last)`
- Iterator operation requirements
- Predicates
- Lambda expressions
- Lambda captures
- Early exit behavior
- Standard library algorithm design
- Writing algorithms that work across multiple container types
- Testing generic algorithms with edge cases

The main lesson from this project is that a generic algorithm should not depend on the exact container type.

Instead, it should require only the operations that are actually necessary for the algorithm to work.

## Project Structure

```text
STL-Algorithm-Toolkit/
├── AlgorithmToolkit.h
├── main.cpp
└── STL-Algorithm-Toolkit.vcxproj
```

- `AlgorithmToolkit.h` contains the generic algorithm implementations.
- `main.cpp` contains usage examples, comparisons with standard library algorithms, and edge-case tests.

## Environment

- C++
- Visual Studio
- STL
