#include "NonTypeTemplateParameter.hpp"

#include <cstring>
#include <iostream>

namespace cpp17
{
    const char s[] = "literal string";
    constexpr auto size = sizeof(s);

    template <const char *str, size_t sz>
    void Print()
    {
        std::cout << "Size: " << sz << ", Contents: " << str << std::endl;
    }

    void stringLiteralAsTemplateParameterDemo()
    {
        Print<s, size>(); // Prints "Size: 15, Contents: literal string"
    }
}