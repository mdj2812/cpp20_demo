#include "cpp17/cpp17Demos.hpp"
#include "cpp20/cpp20Demos.hpp"

#include <iostream>

int main(int, char **)
{
    cpp17::threeCompDemo();
    cpp20::threeWayCompDemo();
    cpp17::threeCompOperatorOverloadDemo();
    cpp20::threeWayOperatorOverloadDemo();

    cpp17::designatedInitializerDemo();
    cpp20::designatedInitializerDemo();
}
