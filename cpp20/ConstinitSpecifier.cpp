#include "ConstinitSpecifier.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp20
{
    void constinitDemo()
    {
        static constinit const char *c = f(true); // OK
        // static constinit const char *d = f(false); // error

        std::cout << c << '\n';
        // std::cout << d << '\n';
    }
}