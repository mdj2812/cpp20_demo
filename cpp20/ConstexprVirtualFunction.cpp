#include "ConstexprVirtualFunction.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp20
{
    struct Memory
    {
        // Capacity in bytes
        virtual constexpr unsigned int capacity() const = 0;
    };

    struct LokiMem : public Memory
    {
        constexpr unsigned int capacity() const override
        {
            return 1024;
        }
    };

    struct ThorMem : public Memory
    {
        constexpr unsigned int capacity() const override
        {
            return 2048;
        }
    };

    template <typename T>
    void run()
    {
        T hw;

        static_assert(hw.capacity() > memoryNeeded, "HW capacity not enough!");

        // run things
    }

    void constexprVirtualFunctionDemo()
    {
        LokiMem loki{};
        ThorMem thor{};

        std::cout << "cpp17: Loki: " << loki.capacity() << " Thor: " << thor.capacity() << '\n';

        // run<LokiMem>();
        run<ThorMem>();
    }
}