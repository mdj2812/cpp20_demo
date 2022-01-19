#include "LambdaCapture.hpp"

#include <iostream>
#include <string>

namespace cpp17
{
    struct Lambda
    {
        auto foo() const
        {
            return [=]
            { std::cout << s << std::endl; }; // (1)
        }
        std::string s = "lambda";
        ~Lambda()
        {
            std::cout << "Goodbye" << std::endl;
        }
    };

    auto makeLambda()
    {
        Lambda lambda; // (2)
        return lambda.foo();
    } // (3)

    void captureListDemo()
    {
        auto lam = makeLambda();
        lam(); // (4)
    }
}