#include "benchmark.hpp"
#include "cpp17/cpp17Demos.hpp"
#include "cpp20/cpp20Demos.hpp"

#include <cmath>
#include <iostream>

int main(int, char **)
{
#if 0
    // Three way comparison
    std::cout << "************ Three way comparison ************\n";
    cpp17::threeCompDemo();
    cpp20::threeWayCompDemo();
    cpp17::threeCompOperatorOverloadDemo();
    cpp20::threeWayOperatorOverloadDemo();
    std::cout << "**********************************************\n\n";

    // Designated initializer
    std::cout << "*********** Designated initializer ***********\n";
    cpp17::designatedInitializerDemo();
    cpp20::designatedInitializerDemo();
    std::cout << "**********************************************\n\n";

    // init-statement in range based loop
    std::cout << "* init-statement in range based loop *\n";
    cpp17::addLineNumber();
    cpp20::addLineNumber();
    cpp17::danglingReference();
    cpp20::ubFree();
    std::cout << "**********************************************\n\n";

    // constexpr virtual function
    std::cout << "********** constexpr virtual function ********\n";
    cpp17::constVirtualFunctionDemo();
    cpp20::constexprVirtualFunctionDemo();
    std::cout << "**********************************************\n\n";

    // constinit
    std::cout << "****************** constinit *****************\n";
    cpp17::withoutConstinitDemo();
    cpp20::constinitDemo();
    std::cout << "**********************************************\n\n";

    // likely unlikely
    std::cout << "************** likely unlikely ***************\n";
    benchmark(cpp17::cos, "Without attributes");
    benchmark(cpp20::cos, "With attributes");
    benchmark<double(double)>(std::cos, "std::cos");
    std::cout << "**********************************************\n\n";

    // no_unique_address
    std::cout << "************* no_unique_address **************\n";
    cpp17::emptyClassDemo();
    cpp20::emptyClassDemo();
    std::cout << "**********************************************\n\n";

    // template lambda
    std::cout << "**************** template lambda *************\n";
    cpp17::genericLambdaDemo();
    cpp20::templateLambdaDemo();
    std::cout << "**********************************************\n\n";
#endif

    // lambda captures
    std::cout << "**************** capture list demo *************\n";
    cpp17::captureListDemo();
    cpp20::captureListDemo();
    std::cout << "**********************************************\n\n";
}
