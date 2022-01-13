#include "RangeBasedLoop.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp17
{
    void addLineNumber()
    {
        for (std::size_t i = 0; i < demoVector.size(); ++i)
        {
            std::cout << i << ' ' << demoVector[i] << '\n';
        }
    }

    void danglingReference()
    {
        for (auto &d : getFoo().items())
        {
            std::cout << d << '\n';
        }
    }
}