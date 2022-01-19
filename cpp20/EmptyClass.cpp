#include "EmptyClass.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp20
{
    struct Y
    {
        int i;
        [[no_unique_address]] Empty e;
    };

    void emptyClassDemo()
    {
        // the size of any object of empty class type is at least 1
        static_assert(sizeof(Empty) >= 1);

        // at least one more byte is needed to give e a unique address
        static_assert(sizeof(X) >= sizeof(int) + 1);

        // empty member optimized out
        std::cout << "sizeof(Y) == sizeof(int) is " << std::boolalpha
                  << (sizeof(Y) == sizeof(int)) << '\n';
    }
}