#include "EmptyClass.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp17
{
    struct Y
    {
        int i;
        Empty e;
    };

    void emptyClassDemo()
    {
        static_assert(sizeof(Empty) >= 1);

        static_assert(sizeof(X) >= sizeof(int) + 1);

        std::cout << "sizeof(Y) == sizeof(int) is " << std::boolalpha
                  << (sizeof(Y) == sizeof(int)) << '\n';
    }
}