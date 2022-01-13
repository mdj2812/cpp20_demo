#include "DesignatedInitializer.hpp"

#include <iostream>
#include <string>

#include "common.hpp"

namespace cpp17
{
    void designatedInitializerDemo()
    {
        DemoStruct a{};

        std::cout << "cpp17: ";
        printDemoStruct(a);

        DemoStruct b{"", 21, 42};

        std::cout << "cpp17: ";
        printDemoStruct(b);
    }
}