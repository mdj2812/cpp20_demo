#include "WithoutConstinitSpecifier.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp17
{
    void withoutConstinitDemo()
    {
        static const char *c = f(true);  // OK
        static const char *d = f(false); // error

        std::cout << c << '\n';
        std::cout << d << '\n';
    }
}