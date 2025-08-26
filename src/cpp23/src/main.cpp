#include <iostream>
#include <print>

import math;

int main()
{
    std::cout << "C++ version: " << __cplusplus << std::endl;

    std::println("add(1, 2) = {}", math::add(1, 2));

    return 0;
}