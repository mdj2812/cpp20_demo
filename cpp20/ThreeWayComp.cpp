#include "ThreeWayComp.hpp"

#include <compare>
#include <iostream>

#include "common.hpp"

namespace cpp20
{
    void threeWayCompDemo()
    {
        constexpr double foo = -0.0;
        constexpr double bar = 0.0;

        constexpr auto res = (foo <=> bar);

        std::cout << "cp20: ";

        if (res < 0)
        {
            std::cout << "-0 is less than 0";
        }
        else if (res > 0)
        {
            std::cout << "-0 is greater than 0";
        }
        else // (res == 0)
        {
            std::cout << "-0 and 0 are equal";
        }

        std::cout << "\n";
    }

    struct Point
    {
        int x;
        int y;
        auto operator<=>(const Point &) const = default;
    };
    // compiler generates all six two-way comparison operators

    void threeWayOperatorOverloadDemo()
    {
        constexpr Point pt1{A.x, A.y};
        constexpr Point pt2{B.x, B.y};

        constexpr auto res = (pt1 <=> pt2);

        std::cout << "cp20: ";

        if (res < 0)
        {
            std::cout << "A is less than B";
        }
        else if (res > 0)
        {
            std::cout << "A is greater than B";
        }
        else // (res == 0)
        {
            std::cout << "A and B are equal";
        }

        std::cout << " ";

        std::cout << std::boolalpha
                  << (pt1 == pt2) << ' '   // false; operator== is implicitly defaulted.
                  << (pt1 != pt2) << ' '   // true
                  << (pt1 < pt2) << ' '    // true
                  << (pt1 <= pt2) << ' '   // true
                  << (pt1 > pt2) << ' '    // false
                  << (pt1 >= pt2) << '\n'; // false
    }
}
