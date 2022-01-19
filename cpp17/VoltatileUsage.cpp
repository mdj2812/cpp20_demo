#include <iostream>

#include "common.hpp"

namespace cpp17
{
    void incrementDecrementOperand()
    {
        volatile int i = 0;
        std::cout << ++i << '\n';
    }

    void directCompundAssignment()
    {
        int a = 1, b = 2;
        volatile int i = 0;

        i += 2;

        b = i = a;
        std::cout << a << ' ' << b << ' ' << i << '\n';
    }

    // deprecated: volatile parameters aren't meaningful to the
    //             caller, volatile only applies within the function
    void func1(volatile short a, volatile short b)
    {
        std::cout << a << ' ' << b << '\n';
    }

    void functionParameter()
    {
        volatile short a{3}, b{4};
        func1(a, b);
    }

    volatile short func2()
    {
        volatile short ret{5};
        return ret;
    }

    void functionReturnValue()
    {
        short m = func2();
        std::cout << m << '\n';
    }

    void copy(Device d)
    {
        auto [me] = d;
        std::cout << me << '\n';
    }

    void structBinding()
    {
        Device A{0xdead};
        copy(A);
    }
}