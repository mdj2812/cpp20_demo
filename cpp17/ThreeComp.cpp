#include "ThreeComp.hpp"

#include <iostream>

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
            if (x < other.x)
            {
                return true;
            }

            if (y >= other.y)
            {
                return false;
            }

            return true;
        }
        bool operator==(const Point &other) const
        {
            return (x == other.x) && (y == other.y);
        }
        bool operator>(const Point &other) const
        {
            if (x > other.x)
            {
                return true;
            }

            if (y <= other.y)
            {
                return false;
            }

            return true;
        }
    };
    // compiler generates all six two-way comparison operators

    void threeCompOperatorOverloadDemo()
    {
        constexpr Point A{1, 1};
        constexpr Point B{2, 1};

        std::cout << "cp20: ";

        if (A < B)
        {
            std::cout << "A is less than B";
        }
        else if (A > B)
        {
            std::cout << "A is greater than B";
        }
        else // (A == B)
        {
            std::cout << "A and B are equal";
        }

        std::cout << "\n";
    }
}