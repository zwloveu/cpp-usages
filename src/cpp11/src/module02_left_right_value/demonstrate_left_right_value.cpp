#include <iostream>
#include <utility>

#include "module02_left_right_value/demonstrate_left_right_value.h"

void target(int &&x)
{
    std::cout << "target right value: " << x << std::endl;
}

void target(int &x)
{
    std::cout << "target left value: " << x << std::endl;
}

template <typename T>
void wrapper(T &&arg)
{
    target(std::forward<T>(arg));
}

void demonstrate_left_right_value_basic()
{
    int a = 5;
    int c = 0;

    try
    {
        if (c == 0)
        {
            throw std::invalid_argument("be divided can not be zero");
        }
        int b = a / c;
        std::cout << b << std::endl;
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument(e.what());
    }

    wrapper(std::move(a));
}