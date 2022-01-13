#pragma once

#include <iostream>
#include <string>

struct PointBase
{
    int x;
    int y;
};

constexpr PointBase A{1, 2};
constexpr PointBase B{2, 1};

struct DemoStruct
{
    std::string str;
    int m{-1};
    int n{42};
};

inline void printDemoStruct(const DemoStruct &in)
{
    std::cout << "str:" << in.str << " m: " << in.m << " n: " << in.n << '\n';
}