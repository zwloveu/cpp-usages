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

    target(a);

    target(5);

    wrapper(std::move(a));

    target(a);

    std::string s1{"hello"};
    std::string s2 = std::move(s1);
    std::cout << "s1 = " << s1 << ", address of s1 is: " << &s1 << std::endl;
    std::cout << "s2 = " << s2 << ", address of s2 is: " << &s2 << std::endl;
}