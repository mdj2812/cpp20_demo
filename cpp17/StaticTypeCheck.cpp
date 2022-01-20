#include "StaticTypeCheck.hpp"

#include <iostream>
#include <type_traits>
#include <vector>

#include "common.hpp"

namespace cpp17
{
    template <typename T>
    T add(T a, T b)
    {
        static_assert(std::is_integral_v<T>);
        return a + b;
    }

    void integralCheckDemo()
    {
        // std::cout << add("1", "2") << '\n'; // Error: const char* fails static_assert
        std::cout << add(1, 2) << '\n';
    }

    template <typename T>
    void cat(T &x, T &y)
    {
        x.append(y).append(" end");
    }

    void hasMemberFuncDemo()
    {
        std::string str1{"123"}, str2{"456"};
        cat(str1, str2);
        std::cout << str1 << '\n';

        // Error: std::vector doesn't have member function T& append(T&)
        // std::vector<char> vec1{'1', '2', '3'}, vec2{'4', '5', '6'};
        // cat(vec1, vec2);
        // std::cout << vec1.data() << '\n';

        // OK: compiler here won't check its return type
        SomeoneWithAppend swa1{"123"}, swa2{"456"};
        cat(swa1, swa2);
        std::cout << swa1.getStr() << '\n';
    }
}