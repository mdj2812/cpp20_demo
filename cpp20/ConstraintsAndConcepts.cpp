#include "ConstraintsAndConcepts.hpp"

#include <concepts>
#include <iostream>
#include <type_traits>
#include <vector>

#include "common.hpp"

namespace cpp20
{
    template <std::integral T>
    T add(T a, T b)
    {
        return a + b;
    }

    void predefinedIntegralConceptDemo()
    {
        // std::cout << add("1", "2") << '\n'; // Error: const char* does not satisfied the constraint
        std::cout << add(1, 2) << '\n';
    }

    template <typename T>
    concept HasFuncAppend = requires(T &a, T &b)
    {
        {
            a.append(b)
            } -> std::same_as<T &>;
    };

    template <typename T>
    requires HasFuncAppend<T>
    void cat(T &x, T &y)
    {
        x.append(y).append(" end");
    }

    void hasMemberFuncConstraintsDemo()
    {
        std::string str1{"123"}, str2{"456"};
        cat(str1, str2);
        std::cout << str1 << '\n';

        // Error: std::vector doesn't have member function T& append(T&)
        // std::vector<char> vec1{'1', '2', '3'}, vec2{'4', '5', '6'};
        // cat(vec1, vec2);
        // std::cout << vec1.data() << '\n';

        // Error: std::vector doesn't have member function T& append(T&)
        // SomeoneWithAppend swa1{"123"}, swa2{"456"};
        // cat(swa1, swa2);
        // std::cout << swa1.getStr() << '\n';
    }
}