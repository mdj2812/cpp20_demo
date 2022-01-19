#include "GenericLambda.hpp"

#include <iostream>

namespace cpp17
{
    auto sumGen = [](auto fir, auto sec)
    { return fir + sec; }; // arbitrary types (C++14)

    void genericLambdaDemo()
    {
        std::cout << "sumGen(2000, 22): " << sumGen(2000, 22) << std::endl;
        std::cout << "sumGen(true, 2021): " << sumGen(true, 2021) << std::endl;
    }
}