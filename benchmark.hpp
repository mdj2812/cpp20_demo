#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

volatile double sink{}; // ensures a side effect

double gen_random() noexcept
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<double> dis(-1.0, 1.0);
    return dis(gen);
}

template <class func>
void benchmark(func fun, const std::string &rem)
{
    const auto start = std::chrono::high_resolution_clock::now();
    for (auto size{1ULL}; size != 10'000'000ULL; ++size)
    {
        sink = fun(gen_random());
    }
    const std::chrono::duration<double> diff =
        std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::fixed << std::setprecision(6) << diff.count()
              << " sec " << rem << std::endl;
}