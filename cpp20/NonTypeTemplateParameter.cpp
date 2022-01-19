#include "NonTypeTemplateParameter.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>

namespace cpp20
{
#if 0
    template <float value>
    struct X
    {
    }; // assume that this is ok

    void function(X<1.0>) {}

    void function(X<1.00000000001>) {} // is this a valid overload?

    void floatingPointAsTemplateParameterDemo()
    {
        function(X<1.0000000000999999>());
        // is it void function( X< 1.00000000001 > ) ?
    }
#endif

    /**
     * Literal class type that wraps a constant expression string.
     *
     * Uses implicit conversion to allow templates to *seemingly* accept constant strings.
     */
    template <size_t N>
    struct StringLiteral
    {
        constexpr StringLiteral(const char (&str)[N])
        {
            std::copy_n(str, N, value);
        }

        char value[N];
    };

    template <StringLiteral lit>
    void Print()
    {
        // The size of the string is available as a constant expression.
        constexpr auto size = sizeof(lit.value);

        // and so is the string's content.
        constexpr auto contents = lit.value;

        std::cout << "Size: " << size << ", Contents: " << contents << std::endl;
    }

    void stringLiteralAsTemplateParameterDemo()
    {
        Print<"literal string">(); // Prints "Size: 15, Contents: literal string"
    }
}