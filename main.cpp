#include "cpp17/cpp17Demos.hpp"
#include "cpp20/cpp20Demos.hpp"

#include <iostream>

int main(int, char **)
{
    // Three way comparison
    cpp17::threeCompDemo();
    cpp20::threeWayCompDemo();
    cpp17::threeCompOperatorOverloadDemo();
    cpp20::threeWayOperatorOverloadDemo();

    // Designated initializer
    cpp17::designatedInitializerDemo();
    cpp20::designatedInitializerDemo();

    // init-statement in range based loop
    cpp17::addLineNumber();
    cpp20::addLineNumber();
    // cpp17::danglingReference();
    cpp20::ubFree();

    // constexpr virtual function
    cpp17::constVirtualFunctionDemo();
    cpp20::constexprVirtualFunctionDemo();

    // constinit
    cpp17::withoutConstinitDemo();
    cpp20::constinitDemo();
}
