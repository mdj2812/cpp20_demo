#include "DesignatedInitializer.hpp"

#include <iostream>
#include <string>

#include "common.hpp"

namespace cpp20
{
    void designatedInitializerDemo()
    {
        DemoStruct a{};

        std::cout << "cpp20: ";
        printDemoStruct(a);

        DemoStruct b{.m = 21}; // Initializes str with {}, which calls the default constructor
                               // then initializes n with = 42
                               // then initializes m with = 21

        std::cout << "cpp20: ";
        printDemoStruct(b);
    }
}