#include <iostream>

#include "common.hpp"

namespace cpp20
{
    void incrementDecrementOperand()
    {
        volatile int i = 0;
        // deprecated: does this access i once or twice
        // ++i;

        // OK, a volatile load, an addition, a volatile store
        i = i + 1;

        std::cout << i << '\n';
    }

    void directCompundAssignment()
    {
        int a = 1, b = 2;
        volatile int i = 0;

        // deprecated: does this access i once or twice
        // i += 2;

        // OK, a volatile load, an addition, a volatile store
        i = i + 2;

        // deprecated: does this access i once or twice
        // b = i = a;

        // OK, a volatile load, an addition, a volatile store
        b = a;
        i = a;

        std::cout << a << ' ' << b << ' ' << i << '\n';
    }

    // deprecated: volatile parameters aren't meaningful to the
    //             caller, volatile only applies within the function
    // void func1(volatile short a, volatile short b);

    // OK, the pointer isn't volatile, the data points to is
    void func1(volatile short *a, volatile short *b)
    {
        std::cout << *a << ' ' << *b << '\n';
    }

    void functionParameter()
    {
        volatile short a{3}, b{4};
        func1(&a, &b);
    }

    // deprecated: a volatile return type has no meaning
    // volatile short func2();
    short func2()
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
        // deprecated: do the binding copy the reg?
        // But no such warning with GCC10?
        auto [me] = d;
        std::cout << me << '\n';
    }

    void structBinding()
    {
        Device A{.reg = 0xdead};
        copy(A);
    }
}