#pragma once

#include <iostream>
#include <string>
#include <vector>

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

static const std::vector<std::string> demoVector = {"hello", ",", "world"};

class Foo
{
public:
    const auto &items()
    {
        return data;
    }

private:
    std::vector<std::string> data{"hello", ",", "world"};
};

inline Foo getFoo()
{
    return Foo();
}

constexpr uint32_t memoryNeeded{2000};

inline const char *g() { return "dynamic initialization"; }
constexpr const char *f(bool p) { return p ? "constant initializer" : g(); }

struct Empty
{
}; // empty class

struct X
{
    int i;
    Empty e;
};

struct Device
{
    volatile int reg;
};
