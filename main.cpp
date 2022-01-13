#include "cpp17/ThreeComp.hpp"
#include "cpp20/ThreeWayComp.hpp"

#include <iostream>

int main(int, char **)
{
    cpp17::threeCompDemo();
    cpp20::threeWayCompDemo();
    cpp17::threeCompOperatorOverloadDemo();
    cpp20::threeWayOperatorOverloadDemo();
}
