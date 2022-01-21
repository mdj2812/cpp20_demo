#include "CoroutineGenerator.hpp"

#include <coroutine>
#include <functional>
#include <iostream>

namespace cpp20
{
    template <typename T>
    struct Generator
    {

        struct promise_type;
        using handle_type = std::coroutine_handle<promise_type>;

        Generator(handle_type h) : coro(h)
        {
            std::cout << "        Generator::Generator" << '\n';
        }

        handle_type coro;

        ~Generator()
        {
            std::cout << "        Generator::~Generator" << '\n';
            if (coro)
                coro.destroy();
        }
        Generator(const Generator &) = delete;
        Generator &operator=(const Generator &) = delete;
        Generator(Generator &&oth) : coro(oth.coro)
        {
            oth.coro = nullptr;
        }
        Generator &operator=(Generator &&oth)
        {
            coro = oth.coro;
            oth.coro = nullptr;
            return *this;
        }
        T getNextValue()
        {
            std::cout << "        Generator::getNextValue" << '\n';
            coro.resume(); // (13)
            return coro.promise().current_value;
        }
        struct promise_type
        {
            promise_type()
            { // (2)
                std::cout << "            promise_type::promise_type" << '\n';
            }

            ~promise_type()
            {
                std::cout << "            promise_type::~promise_type" << '\n';
            }

            std::suspend_always initial_suspend()
            { // (5)
                std::cout << "            promise_type::initial_suspend" << '\n';
                return {}; // (6)
            }
            std::suspend_always final_suspend() noexcept
            {
                std::cout << "            promise_type::final_suspend" << '\n';
                return {};
            }
            auto get_return_object()
            { // (3)
                std::cout << "            promise_type::get_return_object" << '\n';
                return Generator{handle_type::from_promise(*this)}; // (4)
            }

            std::suspend_always yield_value(int value)
            { // (8)
                std::cout << "            promise_type::yield_value" << '\n';
                current_value = value; // (9)
                return {};             // (10)
            }
            void return_void() {}
            void unhandled_exception()
            {
                std::exit(1);
            }

            T current_value;
        };
    };

    Generator<int> getNext(int start = 1, int step = 1)
    {
        std::cout << "    getNext: start" << '\n';
        auto value = start;
        while (true)
        { // (11)
            std::cout << "    getNext: before co_yield" << '\n';
            co_yield value; // (7)
            std::cout << "    getNext: after co_yield" << '\n';
            value += step;
        }
    }

    void generatorDemo()
    {
        auto gen = getNext();

        for (int i = 0; i <= 2; ++i)
        {
            auto val = gen.getNextValue();                // (12)
            std::cout << __func__ << ": " << val << '\n'; // (14)
        }
    }
}