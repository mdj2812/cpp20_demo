#include "ThreeComp.hpp"

#include <iostream>

#include "common.hpp"

namespace cpp17
{
    void threeCompDemo()
    {
        constexpr double foo = -0.0;
        constexpr double bar = 0.0;

        std::cout << "cpp17: ";

        if (foo < bar)
        {
            std::cout << "-0 is less than 0";
        }
        else if (foo > bar)
        {
            std::cout << "-0 is greater than 0";
        }
        else // (foo == bar)
        {
            std::cout << "-0 and 0 are equal";
        }

        std::cout << "\n";
    }

    struct Point
    {
        int x;
        int y;
        bool operator<(const Point &other) const
        {
            if (x == other.x)
            {
                return y < other.y;
            }

            return x < other.x;
        }
        bool operator<=(const Point &other) const
        {
            if (x == other.x)
            {
                return y <= other.y;
            }

            return x < other.x;
        }
        bool operator==(const Point &other) const
        {
            return (x == other.x) and (y == other.y);
        }
        bool operator!=(const Point &other) const
        {
            return (x != other.x) or (y != other.y);
        }
        bool operator>(const Point &other) const
        {
            if (x == other.x)
            {
                return y > other.y;
            }

            return x > other.x;
        }
        bool operator>=(const Point &other) const
        {
            if (x == other.x)
            {
                return y >= other.y;
            }

            return x > other.x;
        }
    };
    // compiler generates all six two-way comparison operators

    void threeCompOperatorOverloadDemo()
    {
        constexpr Point pt1{A.x, A.y};
        constexpr Point pt2{B.x, B.y};

        std::cout << "cp17: ";

        if (pt1 < pt2)
        {
            std::cout << "A is less than B";
        }
        else if (pt1 > pt2)
        {
            std::cout << "A is greater than B";
        }
        else // (pt1 == pt2)
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