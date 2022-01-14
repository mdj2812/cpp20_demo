#pragma once

namespace cpp20
{
    constexpr double pow(double x, long long n) noexcept
    {
        if (n > 0) [[likely]]
            return x * pow(x, n - 1);
        else [[unlikely]]
            return 1;
    }
    constexpr long long fact(long long n) noexcept
    {
        if (n > 1) [[likely]]
            return n * fact(n - 1);
        else [[unlikely]]
            return 1;
    }
    constexpr double cos(double x) noexcept
    {
        constexpr long long precision{16LL};
        double y{};
        for (auto n{0LL}; n < precision; n += 2LL)
        {
            [[likely]] y += pow(x, n) / (n & 2LL ? -fact(n) : fact(n));
        }
        return y;
    }
}