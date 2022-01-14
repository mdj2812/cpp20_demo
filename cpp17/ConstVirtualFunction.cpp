#include "ConstVirtualFunction.hpp"

#include <assert.h>
#include <iostream>

#include "common.hpp"

namespace cpp17
{
    struct Memory
    {
        // Capacity in bytes
        virtual unsigned int capacity() const = 0;
    };

    struct LokiMem : public Memory
    {
        unsigned int capacity() const override
        {
            return 1024;
        }
    };

    struct ThorMem : public Memory
    {
        unsigned int capacity() const override
        {
            return 2048;
        }
    };

    template <typename T>
    void run()
    {
        T hw;

        assert(hw.capacity() > memoryNeeded);

        // run things
    }

    void constVirtualFunctionDemo()
    {
        LokiMem loki{};
        ThorMem thor{};

        std::cout << "cpp17: Loki: " << loki.capacity() << " Thor: " << thor.capacity() << '\n';

        // run<LokiMem>();
        run<ThorMem>();
    }
}