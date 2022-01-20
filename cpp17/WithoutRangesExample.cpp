#include "WithoutRangesExample.hpp"

#include "common.hpp"

namespace cpp17
{
    void evenSquareDemo()
    {
        for (int i : ints)
        {
            if (0 == i % 2)
            {
                std::cout << i * i << ' ';
            }
        }
        std::cout << '\n';
    }
}