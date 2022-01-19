#include "TemplateLambda.hpp"

#include <iostream>

namespace cpp20
{
    auto sumTem = []<typename T>(T fir, T sec)
    { return fir + sec; }; // arbitrary, but identical types (C++20)

    void templateLambdaDemo()
    {
        std::cout << "sumTem(2000, 22): " << sumTem(2000, 22) << std::endl;
        // std::cout << "sumTem(true, 2021): " << sumTem(true, 2021) << std::endl; // ERROR
    }
}