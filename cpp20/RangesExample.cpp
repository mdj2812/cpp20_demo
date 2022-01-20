#include "RangesExample.hpp"

#include <iostream>
#include <ranges>

#include "common.hpp"

namespace cpp20
{
    auto even = [](int i)
    { return 0 == i % 2; };
    auto square = [](int i)
    { return i * i; };

    void evenSquareDemo()
    {
        // "pipe" syntax of composing the views:
        for (int i : ints | std::views::filter(even) | std::views::transform(square))
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}