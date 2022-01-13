#include "RangeBasedLoop.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp20
{
    void addLineNumber()
    {
        for (std::size_t i = 0; auto &d : demoVector)
        {
            std::cout << i++ << ' ' << d << '\n';
        }
    }

    void ubFree()
    {
        for (auto foo = getFoo(); auto &d : foo.items())
        {
            std::cout << d << '\n';
        }
    }
}